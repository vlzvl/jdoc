<?php
ini_set("display_errors",1);error_reporting(E_ALL);
ini_set("memory_limit", -1);
// header
header("Content-Type: text/html; charset=UTF-8\n");
header("Last-Modified: " . gmdate("D, d M Y H:i:s") . " GMT");
header("Cache-Control: no-store, no-cache, must-revalidate");
header("Cache-Control: post-check=0, pre-check=0", false);
header("Pragma: no-cache");

/*

// SOURCES

// most used characters in modend chinese language (3500 in number)
// taken from the official website of the Ministry of Education, China (2005)
// http://lingua.mtsu.edu/chinese-computing/statistics/char/listchangyong.php

// http://www.clavisinica.com/character-test.html

$lines = file("C:/Users/vlzvl/Desktop/chinese.txt");
echo "GLYPH --- HEX --- DEC<br/><br/>";
foreach($lines as $line) {
   $line = preg_replace('!\s+!', ' ', $line);
   $parts = explode(" ", $line);
   echo $parts[5];   // the glyph
   echo "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;".$parts[1];   // hex of glyph
   echo "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;".hexdec($parts[1]);   // dec of glyph
   echo "<br/>";
}
exit;
*/

/*
function ord_utf8($c) {
    $b0 = ord($c[0]);
    if ( $b0 < 0x10 ) {
        return $b0;
    }
    $b1 = ord($c[1]);
    if ( $b0 < 0xE0 ) {
        return (($b0 & 0x1F) << 6) + ($b1 & 0x3F);
    }
    return (($b0 & 0x0F) << 12) + (($b1 & 0x3F) << 6) + (ord($c[2]) & 0x3F);
}
	
include_once("../SP/system/php/simple_html_dom/simple_html_dom.php");
$html_raw = file_get_contents("CHINESE.htm");
$html_raw = preg_replace("/[[:blank:]]+/"," ",$html_raw);
$html_raw = mb_convert_encoding($html_raw, 'UTF-8', 'gb2312');
$html = str_get_html($html_raw);
$codes = array();
$lines = explode("\n", $html->find("pre",0)->plaintext);
foreach($lines as $line) {
   if (empty($line)) {
      continue;
   }
   $frag = explode(" ", $line);
   if ($frag[1] == "?") {
      continue;
   }
   $codes[] = ord_utf8($frag[1]);
}
sort($codes);
echo "uint16_t codepoints[] = {";
foreach($codes as $k=>$code) {
   if ($k > 0) {
      echo ", ";
   }
   echo $code;
}
echo "};";
exit;
*/

// just like 'microtime' but returns 'float' for PHP < 5.0
function SP_microtime() {
   list($usec, $sec) = explode(" ",microtime());
   return ((float)$usec + (float)$sec);
}

function convert_brackets_to_link($string) {
   // find the starting bracket (if one exist)
   $startbracket = strpos($string, "[");
   $endbracket = strpos($string, "]", $startbracket) + 1;
   if ($startbracket !== FALSE && $endbracket !== FALSE) {
      // we enter a loop; as long there are brackets '[..]', we keep change them to links
	  do {
         $entry = substr($string, $startbracket, $endbracket - $startbracket);
	     $entry_wb = substr($entry, 1, -1);   // entry without brackets
	     $string = preg_replace('/\\'.$entry.'/', '<a href="#'.$entry_wb.'">'.$entry_wb.'</a>', $string, 1);
         // find the starting bracket (if one exist)
         $startbracket = strpos($string, "[");
         $endbracket = strpos($string, "]", $startbracket) + 1;
	  } while($startbracket !== FALSE && $endbracket !== FALSE);
	  // return the modified string
	  return $string;
   }
   // if there aren't brackets, we simply return the original string
   return $string;
}

// return the string offset for entry's name (skipping stuff like "map<">)
function get_entry_name_start($entry) {
   // modify $entry to have '<>' so it can be used either unchanged or changed already
   $entry = str_replace(array("&lt","&gt"), array("<",">"), $entry);
   // write only function name (no data types, no parameters); we add a space ' ' to skip return data types start with 'J3D_'
   // if return data type is a "map", things are complex since a " J3D_" can easily found in a map; we need to find the end of map
   if (substr($entry, 0, 4) == "map<") {
      // we loop to count all "<", then we end the loop when all ">" matching all "<" and store the position
	  $map_brackets = 0;
	  foreach(str_split($entry) as $k=>$v) {
	     if ($v == "<") {
		    $map_brackets++;
	     }
		 else if ($v == ">") {
		    $map_brackets--;
			if ($map_brackets == 0) {
			   return $k;
			}
	     }
      }
   }
   return 0;
}

?>
<!DOCTYPE html>
<html>
 <head>
  <title>JDoc</title>
  <meta charset="utf-8">
  <script type="text/javascript" src="jquery-1.6.2.min.js"></script>
  <script type="text/javascript" src="javascript.js"></script>
  <link type="text/css" rel="stylesheet" href="styles.css">
 </head>
 <body>
 
<?php
   $start = SP_microtime();
   $entries = array();
   // add the source files containing JDOC entries
   $JDOC_FILES = array(
      "samples/jolt3d.h"
   );
   // get contents from all files, add them in a raw variable
   $data = "";
   foreach($JDOC_FILES as $file) {
      $data .= file_get_contents($file);
   }
   $data_size = strlen($data);
   $curpos = 0;
   while($curpos < $data_size) {
      // find next doc entry
      $startdoc = strpos($data, "/*jdoc", $curpos);
      if ($startdoc !== FALSE) {
         // read entry's json descriptor; if can't be found, we ignore this doc + entry
	     $jsonstart = strpos($data, "{", $startdoc);
	     if ($jsonstart !== FALSE) {
	        $json = substr($data, $jsonstart, strpos($data, "}", $startdoc) - $jsonstart + 1);
		    $djson = json_decode($json, TRUE);
         }
	     else {
            $enddoc = strpos($data, "*/", $startdoc);
		    $curpos = $enddoc + 2;
	        continue;
	     }
	     // based on entry type, we fill with parsed information (if 'type' does not exist, it's assumed as 'entry')
   	     if (!isset($djson["type"]) || $djson["type"] == "entry") {
	        // read entry
            $enddoc = strpos($data, "*/", $startdoc);
            $startentry = strpos($data, "*/", $enddoc) + 2;
            $endentry = strpos($data, ");", $startentry) + 2;
            $entry = trim( substr($data, $startentry, $endentry - $startentry) );
			$entry_name_offset = get_entry_name_start($entry);
	        $namestart = strpos($entry, " J3D_", $entry_name_offset);
	        $nameend = strpos($entry, "(", $namestart);
            $nameentry = trim( substr($entry, $namestart, $nameend - $namestart) );
		    // params
		    $params = array();
	        $paramsstart = strpos($entry, "(") + 1;
	        $paramsend = strpos($entry, ");");
			$params_length = ($paramsend-$paramsstart);
			// if there are parameters and jdoc has an entry 'params'
			if ($params_length > 0 && isset($djson["params"])) {
		       $paramsraw = substr($entry, $paramsstart, $paramsend - $paramsstart);
               $eparamsraw = explode(", ", $paramsraw);
		       foreach($eparamsraw as $param) {
			      // if '=' exists in param, it means a default value is given. We need to throw the text after '='.
			      if (($peq = strpos($param, "=")) !== FALSE) {
			         $param = trim( substr($param, 0, $peq) );
			      }
		          $eparam = explode(" ", $param);
				  $theparam = $eparam[ sizeof($eparam)-1 ];   // add only the last fragment -- the param's name (as default)
				  // if ')(' and '(*' characters are found, then parameter is a callback
			      if (strpos($param, ")(") !== FALSE && ($peq = strpos($param, "(*")) !== FALSE) {
			         $theparam = trim( substr($param, $peq+2, strpos($param, ")") - ($peq+2)) );
				  }
			      $params[] = $theparam;
		       }
		       // swap json params to the names found
		       foreach($params as $k=>$param) {
			      // in case function parameters are different than the ones provided through 'params', we skip them
			      if (!isset($djson["params"][$k])) {
				     break;
				  }
		          $djson["params"][ $params[$k] ] = $djson["params"][$k];
			      unset( $djson["params"][$k] );
		       }
			}
		    // add to entries
		    $entries[ $nameentry ] = $djson;   // copy parsed json + apply some more
	        $entries[ $nameentry ] += array(
		       "params"=>$params,
		       "nameonly"=>$nameentry,
		       "name_and_declaration"=>str_replace(array("<",">"), array("&lt","&gt"), $entry)
		    );
            $curpos = $endentry + 2;
	     }
   	     else if ($djson["type"] == "define") {
	        // read defines; the "rule" to follow is that #defines should have no empty lines in between (in this case, the loop exits)
			$curpos = strpos($data, "*/", $startdoc) + 2;
			$curpos = strpos($data, "\n", $curpos) + 1;
			$body = "";
			while(TRUE) {
			   $endpos = strpos($data, "\n", $curpos) - 1;
			   $entry = trim( substr($data, $curpos, $endpos - $curpos) );
			   // if new line does not start with '#define', we're done (we don't update the 'curpos' to let another code to handle it)
			   if (empty($entry) || substr($entry,0,7) != "#define") {
			      break;
			   }
			   $body .= ($entry."<br/>");
			   $curpos = $endpos + 2;
			}
		    // add to entries
			$nameentry = $djson["group"];
		    $entries[ $nameentry ] = $djson;   // copy parsed json + apply some more
	        $entries[ $nameentry ] += array(
		       "body"=>"<pre style='margin:0;padding:0'><code>".str_replace("\n","",$body)."</code></pre>"
		    );
		 }		 
	     else {
            $enddoc = strpos($data, "*/", $startdoc);
		    $curpos = $enddoc + 2;
	        continue;
	     }
      }
      // not doc? we're done
      else {
         break;
      }
   }
?>

<div class="docleft">
<?php
   foreach($entries as $k=>$v) {
      if (!isset($v["type"]) || $v["type"] == "entry") {
         // if entry belongs to a group group, write the group first
         if (isset($v["group"])) { ?>
   <div class="group"> <?php echo $v["group"]; ?> </div>
<?php    } ?>
   <div class="entry">
    <a href="#<?php echo $v["nameonly"]; ?>"><?php echo $v["nameonly"]; ?></a>
   </div>
<?php }
   }
?>
</div>

<div class="docright">
<?php
   foreach($entries as $k=>$v) {
      if (!isset($v["type"]) || $v["type"] == "entry") {
?>
 <div id="<?php echo $v["nameonly"]; ?>" class="entrydetail">
  <h2>Declaration</h2>
  <div class="declaration">
<?php
   // measure the parameters length, to avoid some newlines when 'prettifying' them
   $startparams = strpos($v["name_and_declaration"], "(") + 1;
   $endparams = strpos($v["name_and_declaration"], ")", $startparams);
   $params_length = ($endparams - $startparams);
   // make bold the function's name
   $temp = substr_replace($v["name_and_declaration"], "<b> J3D_", strpos($v["name_and_declaration"], " J3D_", get_entry_name_start($v["name_and_declaration"])), strlen(" J3D_"));
   $temp = substr_replace($temp, "</b>(", strpos($temp, "("), strlen("("));
   // move params (if they exist) into their own line and apply space in front of them (readability++)
   if ($params_length > 0) {
      $temp = substr_replace($temp, "(<br/><span style='margin-left:30px'></span>", strpos($temp, "("), strlen("("));
      $temp = str_replace(", ", ",<br/><span style='margin-left:30px'></span>", $temp);
      $temp = str_replace(");", "<br/>);", $temp);
   }
   echo $temp;
?>
  </div>
  <h2>Parameters</h2>
  <div class="parameters">
<?php 
   // function does not have parameters
   if (empty($v["params"])) { ?>
   <div class="param">
    <div class="none">None</div>
   </div>
<?php }
   // function has parameters
   else {
      foreach($v["params"] as $k=>$v2) { ?>
   <div class="param">
    <div class="name"> <?php echo $k; ?> </div>
    <div class="desc"> <?php echo convert_brackets_to_link( $v2 ); ?> </div>
   </div>
<?php } 
   }
?>
  </div>
  <h2>Description</h2>
  <div class="description">
<?php
   echo convert_brackets_to_link( $v["desc"] );
?>
  </div>
  <h2>Return</h2>
  <div class="return">
<?php echo convert_brackets_to_link( $v["return"] ); ?>
  </div>
 </div>
<?php }
      // #defines
      else if ($v["type"] == "define") { ?>
 <div id="<?php echo $v["group"]; ?>" class="entrydetail">
  <h2> <?php echo $v["group"]; ?> </h2>
  <div class="declaration">
   <?php echo $v["body"]; ?>
  </div>
 </div>
<?php }
   } 
?>
</div>

 </body>
</html>