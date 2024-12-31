console.log("\n\t\t\tEXERCISE 1\n");

const set = new Set([1,1,2,3,4]);

console.log(set);

console.log("\n\t\t\tEXERCISE 3\n");

const name = "Lydia";
age = 21;

console.log(delete name);
console.log(delete age);

console.log("\n\t\t\tEXERCISE 4\n");

const numbers = [1,2,3,4,5];
const [y] = numbers;

console.log(y);

console.log("\n\t\t\tEXERCISE 5\n");

const user = {name: "Lydia", age: 21};
const admin = {admin: true, ...user};

console.log(admin);

console.log("\n\t\t\tEXERCISE 6\n");

const person = {name: "Lydia"};

Object.defineProperty(person, "age", {value: 21});

console.log(person);
console.log(Object.keys(person));

console.log("\n\t\t\tEXERCISE 7\n");

const a = {};
const b = {key: "b"};
const c = {key: "c"};

a[b] = 123;
a[c] = 456;

console.log(a[b]);

console.log("\n\t\t\tEXERCISE 8\n");

let num = 10;

const increaseNumber = () => num++;
const increasePassedNumber = number => number++;

const num1 = increaseNumber();
const num2 = increasePassedNumber(num1);

console.log(num1);
console.log(num2);

console.log("\n\t\t\tEXERCISE 9\n");

const value = {number: 10};

const multiply = (x = {...value}) => {console.log((x.number *= 2));
};

multiply();
multiply();
multiply(value);
multiply(value);

console.log("\n\t\t\tEXERCISE 10\n");

[1,2,3,4].reduce((x,y) => console.log(x,y));