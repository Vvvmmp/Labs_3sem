console.log('\nЗАДАНИЕ 1\n');

console.log(basicOperation('/', 5, 10));
 function basicOperation(operation, value1, value2)
{
    switch (operation)
    {
        case '+':
            return Number(value1) + Number(value2);
        case '-':
            return Number(value1) - Number(value2);
        case '/':
            return Number(value1) / Number(value2);
        case '*':
            return Number(value1) * Number(value2);
        default:
         throw new Error('некорректный ввод');
    }
}
// basicOperation('/', 5, 10);

console.log('\nЗАДАНИЕ 2\n');
function number2(n)
{
    let result = 0;
for(let i = 1; i <= n; i++)
{
   result += Math.pow(i,3);
}
console.log(result);
}
number2(5);

console.log('\nЗАДАНИЕ 3\n');
function number3(array)
{
    let average = 0;
    let i = 0;
    array.forEach(numbers => {
        average += numbers;
        i++
    });
    return average / i;
}
let inputArray = [1, 2, 3, 4, 5];
let sumArray = number3(inputArray);
console.log(sumArray);

console.log('\nЗАДАНИЕ 4\n');
function number4(str)
{
    let result = str.replace(/[^a-zA-Z]+/g, '').split('').reverse().join('');
    return result;
}
let str = 'Xпривет, hel8lo?';
let invertedEngWords = number4(str);
console.log(invertedEngWords);

console.log('\nЗАДАНИЕ 5\n');
function number5(n, s)
{
   return s.repeat(n);
}
let n5 = number5(5, 'Привет');
console.log(n5);

console.log('\nЗАДАНИЕ 6\n');
function number6(arr1, arr2)
{
   let array3 = [];
   for (let i = 0; i < arr1.length; i++)
   {
    let Unique = true;
    for (let j = 0; j< arr2.length; j++)
    {
        if(arr1[i] === arr2[j])
        {
            Unique = false;
            break;
        }
    }
    if(Unique)
    {
        array3.push(arr1[i]);
    }
   }
   return array3;
}
let array1 = ['Пн', 'Ср'];
let array2 = ['Ср', 'Чт'];
let resultn6 = number6(array1, array2);
console.log(resultn6);


