

// Task 1

// JavaScript program to print expected Output using following array.
// Sample array : myColor = ["Red", "Green", "White", "Black"];

// Tast 1.1


let myColor = ["Red", "Green", "White", "Black"];

// Expected output Red,Green,White,Black

let task1 = document.getElementById("task1-1");
task1.innerHTML = myColor;

// tast 1.2

//Expected output Red+Green+White+Black

let task12 = document.getElementById("task1-2");
task12.innerHTML = myColor.join("+");


// task 1.3

// Expected output Red,Green,White


let task13 = document.getElementById("task1-3");
task13.innerHTML = myColor.slice(0, 3);



// task 1.4

// Expected output Red


let task14 = document.getElementById("task1-4");
task14.innerHTML = myColor[0];



// task 1.5

// Expected output Green,White



let task15 = document.getElementById("task1-5");
task15.innerHTML = myColor.slice(1, 3);



// task 1.6

// Expected output Red,Green,White,Black,orange 



let task16 = document.getElementById("task1-6");

myColor.push("orange");

task16.innerHTML = myColor;



// Task 2 // to get sum of all array element using for loop and foreach loop.


let num = [10, 2, 45, 6, 8, 15, 23]
let sum = 0;

num.forEach(n => sum += n);

document.getElementById("task2").innerHTML = sum;


// Task 3 //  print a maximum and minimum value of given array.(using function and logic)


let num1 = [2, 23, 56, 5, 89];

function maxmin(arr) {
    let max = arr[0];
    let min = arr[0];

    for (var i = 0; i < arr.length; i++) {
        if (arr[i] > max) {

            max = arr[i];

        } else if (arr[i] < min) {

            min = arr[i];
        }
    }

    return "Maximum nuberm is :- " + max + "<br/> Minimum number is :- " + min;

}


document.getElementById("task3").innerHTML  = maxmin(num1);


// Task 4 // convert all array element in ASCII value. 


let char = ['a','D', 'H', 'm','Y','p','G'];

let value= char.map( ch => ch.charCodeAt(0));

let task4 = document.getElementById("task4");

task4.innerHTML = "Ascii Value is " +value;


// Task 5 //  remove negative values using the filter array function.
 // numbers = [-23,-20,-17, -12, -5, 0, 1, 5, 12, 19, 20];


  let numbers = [-23,-20,-17, -12, -5, 0, 1, 5, 12, 19, 20];

  let postive = numbers.filter( n => n >= 0);

  let task5 = document.getElementById("task5");

  task5.innerHTML = "Postive number is " + postive;
  
// Task 6 // using array map() method and return the square of array element.
// arr = [2, 5, 6, 3, 8, 9];

let arr1 = [2, 5, 6, 3, 8, 9];

let square = arr1.map( num => num*num);

let task6 = document.getElementById("task6");

task6.innerHTML = " The square of array element " +square;

// Task 7 // sort array in ascending descending.
// numbers = [23,20,17, 12,5, 0, 1, 5, 12, 19, 20];


let number1 = [23,20,17, 12,5, 0, 1, 5, 12, 19, 20];

number1.sort();

let ascd = number1;

number1.sort((a,b) => b-a);

let decd = number1;

let task7 = document.getElementById("task7");

task7.innerHTML = "The ascending order is "+ ascd + " The descding order " + decd ;


// Task 8 // filters out any string which is less than 8 characters. 
//words = ['Python', 'Javascript', 'Go', 'Java', 'PHP', 'Ruby'];
 

let words = ['Python', 'Javascript', 'Go', 'Java', 'PHP', 'Ruby'];
 
let w1 = words.filter( (wd) => wd.length < 8);

let task8 = document.getElementById("task8");

task8.innerHTML = "Less than 8 char is :"+ w1;



// Task 9 // JavaScript program to  to print expected output for following string.
// x = "airplane";    output:- r
//x = "oxoxoxox";   output:- "oXoXoXoX"
//x = "A New Java Book";   
// output:-  "a new java book" , "A NEW JAVA BOOK"


let x="airplane";

let ot = x.charAt(2);

let x1="oxoxoxox"
let res="";

for(var i=0; i<x1.length; i++){
    if(i%2==0){
        res += x1[i].toLowerCase();
    }else{
        res += x1[i].toUpperCase();
    }
}



let x2="A new Java Book";

let ot2= x2.toLowerCase();
let ot3= x2.toUpperCase();


let task9 = document.getElementById("task9");

task9.innerHTML = "The ouput is "+ ot + "<br/>The output is "+ res +" <br/> The output is "+ ot2 + "<br/> The output is "+ot3;


// Task 10 // program for array reverse.

let n1 = [1, 2, 3, 4, 5, 6, 7];
let rev=[];

for(var i=0; i<n1.length; i++){

    rev[i] = n1[n1.length-1-i];
}

let task10 = document.getElementById("task10");

task10.innerHTML = "The reverse element is "+ rev ;

// Task 11 //check value is found or not?


let n2 = [10, 12 , 15, 21, 25, 26];
let value1 = 15;
let task11 = document.getElementById("task11");
if(n2.includes(15)){
    task11.innerHTML = " This Value " + value1 + " is find give by array "+ n2; 
}else
    {
        task11.innerHTML = " This Value " + value1 + " is  not find give by array "+ n2; 
   
}

// Task 12 //  print your name and write the no of total character

let nam = "Tushar Patel";
let total = nam.length;

let task21 = document.getElementById("task21");

task21.innerHTML = "Name :- " + nam + " <br/> Total Character is "+ total ; 


// Task 13 // this output using replace concept.


let text = "I often take a walk with my dog in the evening. His dog follows him everywhere. I don't feed my dog in the morning";

let output = text.replaceAll("dog", "Cat");

let Task22 = document.getElementById("task22");

Task22.innerHTML = output;

// Task 14 //  program convert string to array.
// Input :- "Hire the top 1% freelance developers";
// Output :- ["Hire", "the", "top", "1%"] 


let  Input = "Hire the top 1% freelance developers";

let narr = Input.split(" ");

let nom= narr.slice(0, 4);

let word1= nom.map( w => `"${w}"`);

let result = word1.join(",");

let task23 = document.getElementById("task23");

task23.innerHTML = "Output is :- "+ result;



// Task 15 // convert for array to string.
// Input:- ['5', 32, 'Daniel'];
// Output: 5,32,Daniel

let input = ['5', 32, 'Daniel'];

let st=  input.toString();

let task24 = document.getElementById("task24");

task24.innerHTML = st;


