
//  reverse a given number using a loop.

var num=12345;
var revese=0;


while(num > 0){

    var lastdigit = num % 10; 

    revese = (revese*10) + lastdigit;

    num = Math.floor(num/10); 



}

console.log(" Reveser num is: ", revese);
document.getElementById("rev").innerHTML= "The Reverse num is:- "+ revese;

// whether a number is a palindrome.

var num = 121;
var str= String(num);
var isplindrom = true;
var length = str.length;

for(var i=0; i < length / 2; i++){

    if(str[i] !== str[length - 1 -i]){

        isplindrom = false;
        break;
    }
}


if(isplindrom){

    console.log(num, " is a Palindrom");
    document.getElementById("palidrom").innerHTML= "The Palindrom num is:- "+ num;

    
}else{
    console.log(num, " is a not Palindrom");

    document.getElementById("palidrom").innerHTML= "The Palindrom num is:- "+ num;

}




//   Fibonacci series up to n terms using a loop.


var n=10;
var n1=0; n2=1;
var nextTerm;
var series="";

console.log(" Fibonaci series is  " + n + " terms:");



for(var i=1; i<=n; i++ ){ 

    console.log(n1);
    series += n1+" ";

    nextTerm= n1+n2;
    n1=n2;
    n2=nextTerm;
    
}

document.getElementById("fib").innerHTML= "The Fibocnaci series is " + series;


//factorial of a number using a loop.

var fab=6;
var facotiral = 1;

for(var i=1; i<= fab; i++){

    facotiral *= i; 

}

console.log("Factorial num "+ fab + " is ", facotiral);
document.getElementById("fac").innerHTML= "The Factorail number " + fab +" is:- "+ facotiral;


// whether a number is a prime numbe 

var n=11;
var isprime=true;

if(n<=1){

    isprime=false;

}else {

    for(var i=2; i*i<=n; i++){
        if(n%i === 0){
                isprime=false;
                break;
        }
    }
} 
if(isprime){

    console.log( n," is Prime Number");
    document.getElementById("prime").innerHTML= "The prime number is:- "+ n1;
    
}else{
    
    console.log( n, "is not a Prime Number");
    document.getElementById("prime").innerHTML= "This is not a prime number:- "+ n1;
    
}


//  count the total number of digits in a given number

var number=15645;
var count = 0;

if(number === 0){
    count = 1;
}else{
    for(; number>0; count++){

        number =Math.floor(number/10);
        
    }
  
}
console.log( "The total number of digit is",+ count);
document.getElementById("tot").innerHTML= "The total number of digit is:- "+ count;


//  calculate the sum of digits of a number.

var num =256454;
var sum = 0;
var total=num;

while (total>0) {
    sum += total % 10;
    
    total=Math.floor(total/10);
}

console.log(" The  sum of the digit of " ,+num +" is:- " +sum);
document.getElementById("sum").innerHTML= "The sum  of the "+ num + " digit  is:- "+ sum;


// check whether a number is an Armstrong number.

var number = 153; 
var numberString = String(number);
var numberOfDigits = numberString.length;
var sum = 0;

for (var i = 0; i < numberOfDigits; i++) {
    var digit = parseInt(numberString[i]); 
    sum += digit ** numberOfDigits; 
}

if (sum == number) {
    console.log(number + " is an Armstrong number.");
    document.getElementById("arm").innerHTML= "The is a Armstrong num is:- "+ number;
} else {
    console.log(number + " is not an Armstrong number.");
    document.getElementById("arn").innerHTML= "The is not a Armstrong num:- "+ number;
}


// the power of a number using a loop.

var base = 4;
var exponent = 6;
var result = 2; 


for (var i = 0; i < exponent; i++) {
  result *= base;
}

console.log(base + " the power of " + exponent + " is: " + result); 
document.getElementById("power").innerHTML= "The powers number is:- "+ result;

// print the following number pattern:

var pt1='';

for(var i=1; i<=5; i++){
    var raw='';

    for(var j=1; j<=i; j++){

        raw += j;
    }
    
    pt1 += raw + '<br/>';
}

console.log(pt1);

document.getElementById("pt").innerHTML= pt1;
