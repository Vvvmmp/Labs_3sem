console.log("\nЗАДАНИЕ 1\n");
function makeCounter(){
    let currentCount = 1;

    return function() {
        return currentCount++;
    };
}

let counter = makeCounter();

console.log( counter());
console.log( counter());
console.log( counter());

let counter2 = makeCounter();
console.log(counter2());

currentCount = 1;
function makeCounter1(){
    return function() {
        return currentCount++;
    };
}

counter = makeCounter1();
counter2 = makeCounter1();

console.log( counter());
console.log( counter());

console.log(counter2());
console.log(counter2());

console.log("\nЗАДАНИЕ 2\n");

function resultV(a) {
    return (b)=>{
        return (c)=>{
            if( a === b && b === c)
                return pow(a,3);
            return a*b*c;
        }
    }
}

let par1 = resultV(3)(6)(2);
console.log(par1); //36

let par21 = resultV(3);
let par22 = par21(4);
let par2 = par22(5);
console.log(par2); //60

console.log("\nЗАДАНИЕ 3\n");

function* generateSteps(){

    let x = 0;
    let y = 0;

    while(true){
        let choice = yield;
    
        switch(choice){
            case "up":
            y+=10;
            break;

            case "down":
            y-=10;
            break;

            case "right":
            x+=10;
            break;

            case "left":
            x-=10;
            break;
        }
        console.log(`X= ${x}, y= ${y}`);
    }
}

let number2 = generateSteps();
generateSteps().next;
for(let i = 0; i <=10; i++) {
    number2.next(prompt(`Введите направление(up,down,left,right): `,'up'));
}

console.log("\nЗАДАНИЕ 4\n");

let globalVar1 = 123;
let globalVar2 = "1234";
function globalFunc(){
    return "before override";
}

const allGlobalVariables = Object.keys(window);
console.log("Глобальные переменные и функции:");
allGlobalVariables.forEach(variable => {
    console.log(variable, "=", window[variable]);
});

window.globalVar1 = 555;
window.globalVar2 = "1111";
window.globalFunc = function() {
    return "after override";
}

console.log(`globalVar1= ${globalVar1}, globalVar2= ${globalVar2}, globalFunc= ${globalFunc}`);