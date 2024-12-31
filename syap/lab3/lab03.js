console.log("\nЗАДАНИЕ 1\n");
 let array1 = [1, [1, 2, [3, 4]], [2, 4]];
// let array11 = [1, 1, 2, 3, 4, 2, 4];
// console.log(array1);
// console.log(array1.flat());
// console.log(array1.flat(2));

let result1 = array1.reduce((buff, current) => {
    if (Array.isArray(current) ) {
        return buff.concat(current.flat())
    }
    else
    return buff.concat(current)
    }, [])
console.log(result1);

console.log("\nЗАДАНИЕ 2\n");
let array2 = [1, [1, 2, [3, [1, 1], 4]], [2, 4]];
let sum = array2.flat(Infinity).reduce((sum, current) => sum + current, 0);
console.log(sum);

console.log("\nЗАДАНИЕ 3\n");
var student = [
   {
    name: "Vlad",
    age: 18,
    groupId: 8,
    },
    {
    name: "Vadim",
    age: 17,
    groupId: 8,
    },
    {
    name: "Mikhail",
    age: 9,
    groupId: 1,
    }
];
let fasfs = function number3(ageInput)
{
    return student.filter((student => student.age >= ageInput));
}
let ageInput = 17;
console.log(`Cтуденты, достигшие возраста ${ageInput} лет: `);

fasfs(ageInput).forEach(student => {
    console.log(student.name);
});

console.log("\nЗАДАНИЕ 4\n");

function number4(t1, t2)
{
    let toAsciCode = Array.from(t1).reduce((nmb, that) => nmb * 1000 + that.charCodeAt(0), 0); 
    console.log(toAsciCode);
    let secondVal = Array.from(t2);
    console.log(secondVal);
    for ( var i = 0; i < secondVal.length; i++)
    {
        if ( !secondVal[i].search(7))
        {
            secondVal.splice(i,1,'1');
        }            
    }
    let result = secondVal.reduce((tmp, that) => tmp* 10 + Number(that), 0);
    console.log(result);
    return toAsciCode - result;
}
let total1 = "hello";
let total2 = "1273417";
console.log(number4(total1, total2));

console.log("\nЗАДАНИЕ 5\n");

function number5(t1, t2)
{
    let resultObj = Object.assign({}, t1, t2);

    console.log(resultObj);
}
let obj1 = {c1: 5, c2: true, c3: "sdg"};
let obj2 = {c4: 6, c5: 322};

number5(obj1, obj2)

console.log("\nЗАДАНИЕ 6\n");

function number6(height) {
    for (let i = 0; i < height; i++) {
        const spaces = ' '.repeat(height - i - 1);
        const stars = '*'.repeat(2 * i + 1);
        console.log(spaces + stars);
    }
}
number6(5)