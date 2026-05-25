let slide = [
    "https://png.pngtree.com/background/20230223/original/pngtree-beautiful-nature-norway-natural-landscape-picture-image_2047776.jpg",

    "https://png.pngtree.com/thumb_back/fh260/background/20230216/pngtree-beautiful-nature-norway-natural-landscape-image_1600087.jpg",

    "https://tse4.mm.bing.net/th/id/OIP.BRTl3YcXTwjbej7T_BRMcgHaEK?w=700&h=394&rs=1&pid=ImgDetMain&o=7&rm=3",

    "https://vistapointe.net/images/two-jack-lake-wallpaper-9.jpg",

    "https://wallpapercave.com/wp/wp8620713.jpg",

    "https://wallpaperaccess.com/full/5749165.jpg"
];

let current = 0;

let box = document.getElementById("slide");

let counter = document.getElementById("counter");


function slideshow(){

    box.src = slide[current];

    counter.textContent = `${current + 1}/${slide.length}`;
}



function nextSlide(){

    current++;

    if(current >= slide.length){
        current = 0;
    }

    slideshow();
}



document.getElementById("next").addEventListener("click", () => {

    current++;

    if(current >= slide.length){
        current = 0;
    }

    slideshow();
});



document.getElementById("prev").addEventListener("click", () => {

    current--;

    if(current < 0){
        current = slide.length - 1;
    }

    slideshow();
});



setInterval(nextSlide, 2000);



slideshow();