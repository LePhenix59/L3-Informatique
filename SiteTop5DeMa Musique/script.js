$(function () {
    var $mainMenuItems = $("#main-menu ul").children("li");
    var totalMainMenuItems = $mainMenuItems.length;
    var openedIndex = -1;

/*    var init = function () {

        $mainMenuItems.children(".images").click(function () {
            var newIndex = $(this).parent().index(),
            $item = $mainMenuItems.eq(newIndex),
            $colorImage = $item.find(".color");

            $colorImage.animate({left:"0px"},250);

            $item.animate({width:"420px"},250);
        });
    };
*/


    var init = function () {

        $mainMenuItems.children(".images").click(function () {
            var newIndex = $(this).parent().index(),
            $item = $mainMenuItems.eq(newIndex),
            $colorImage = $item.find(".color");

            if (openedIndex === newIndex)
            {
                animateItem($item,false,250);
                openedIndex = -1;
            }
            else
            {
                if ((newIndex>=0) && (newIndex <totalMainMenuItems) )
                {
                    animateItem($mainMenuItems.eq(openedIndex), false, 250);                         
                    openedIndex = newIndex;
                    animateItem($item, true, 250); 
                }
            }
                   
        });
    };
    animateItem = function($item,toOpen,speed)
    {
        var $colorImage = $item.find(".color"),
        itemParam,colorImageParam;

        if (toOpen)
        {
            itemParam ={width:"420px"};
            colorImageParam ={left:"0px"}
        }
        else
        {
            itemParam ={width:"140px"};
            colorImageParam ={left:"140px"}
        }
        $colorImage.animate(colorImageParam,speed);
        $item.animate(itemParam,250);  
    }
    init();
	
});


$(function (){
    $("h4").show();
	$("p").hide();
	$("h3").click(function(){
        $("h4").slideToggle();
        $("p").slideToggle();
    })
})



