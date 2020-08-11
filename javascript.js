var sel_entry = "";   // selected entry
$(document).ready(function() {
   // modify the left margin of 'docright' by the width of 'docleft'
   var docleft_width = $("div.docleft").width();
   $("div.docright").css({"margin-left":parseInt(docleft_width + 30)+"px"});
   // add a target '_blank' for any anchor has a 'href' starting with 'http' (outer internet)
   $("a[href^='http']").attr("target", "_blank");
   // click a link leads to function description
   $("a").click(function() {
      // if anchor has 'target', it's a wide call and should not seek content on this page
      if ($(this).attr("target") !== undefined) {
         return;
	  }
      // hide previous selected (if exist)
	  if (sel_entry != "") {
	     $("div[id='"+sel_entry+"']").css({"display":"none"});
	  }   
      sel_entry = $(this).text();
	  // show selected
	  $("div[id='"+sel_entry+"']").css({"display":"block"});
	  // at least in Google Chrome, scrollbar stays in same position if it was at very bottom; we reset it to the top
	  $("div[id='"+sel_entry+"']")[0].scrollTop = 0;
   });
});