let a = 5;
let name = "Name";
let i = 0;  
let double = 0.23;
let result = 1/0;
let answer = true;
let no = null;

function count(){
    let lengthA = 45;
    let lengthB = 5;
    let widthA  = 21;
    let widthB  = 5;
    let countSquare = lengthA*widthA/lengthB/widthB;
    Math.trunc(countSquare);
    console.log(Math.trunc(countSquare));
}
count();
function number3()
{
    let i = 2;
    let a = ++i;
    let b = i++;
    if(a === b)
    {
        console.log('А= ',a,' равно Б= ',b);
    }
    else{
          if(a > b){
            console.log('А= ',a,' больше, чем Б= ',b);
        }
        else
        {
            console.log('А= ',a,' меньше, чем Б= ',b);
        }
    }
}
number3();

function number4()
{
   const n1 =  ('Котик' === 'котик') ? true : false;
   const n2 =  ('Котик' === 'китик') ? true : false;
   const n3 =  ('Кот' === 'Котик') ? true : false;
   const n4 =  ('Привет' === 'Пока') ? true : false;
   const n5 =  (false === 0) ? true : false;
   const n6 =  (54 === true) ? true : false;
   const n7 =  (123 === false) ? true : false;
   const n8 =  (true === '3') ? true : false;
   const n9 =  (3 === '5мм') ? true : false;
   const n10 =  (8 === '-2') ? true : false;
   const n11 =  (34 === '34') ? true : false;
   const n12 =  (null === undefined) ? true : false;
   console.log(n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11);
}
number4();

function number5()
{
    let admin = 'Влад';
    let user = prompt('Введите имя преподавателя',);
    let user1 = user.toLowerCase(); 
    if(user1.includes('влад'))
    {
        console.log(true);
       
    }
    else
    {
        console.log(false);
    }
}
number5();

function number6()
{
    let firstExam = true;
    let secondExam = true;
    let thirdExam = true;
    
    if(firstExam && secondExam && thirdExam)
    {
        console.log('Вы переведены на следующий курс!');
    }
    else if((firstExam && secondExam) || (firstExam && thirdExam) || (secondExam && thirdExam) )
    {
        console.log('Вы отправлены на пересдачу');
    }
    else
    {
        console.log('Вы отчислены');
    }
}
number6();

function number7()
{
    let nn1 = true + true;
    let nn2 = 0 + "5";
    let nn3 = 5 + "мм";
    let nn4 = 8/Infinity;
    let nn5 = 9 * "\n9";
    let nn6 = null - 1;
    let nn7 = "5" - 2;
    let nn8 = "5px" - 3;
    let nn9 = true - 3;
    let nn10 = 7 || 0;
    console.log(nn1, nn2, nn3, nn4, nn5, nn6, nn7, nn8, nn9, nn10)
}
number7();

function number8()
{
for(let i = 1; i <= 10; i++)
{
    if( i%2 === 0)
    {
        let abc = i + 2;
        console.log(abc);
    }
    else
    {
        let abc1 = i + "мм";
        console.log(abc1);
    }
}
}
number8();

// function number9()
// {
// let days = ['Понедельник', 'Вторник', 'Среда', 'Четверг', 'Пятница', 'Суббота', 'Воскресенье'];
// let input = prompt('Введите день недели:');
// console.log(days[input-1]);
// }
// number9();

function number9()
{
let days = {
    1: 'Понедельник',
    2: 'Вторник',
    3: 'Среда',
    4: 'Четверг',
    5: 'Пятница',
    6: 'Суббота',
    7: 'Воскресенье'    
};
let input = prompt('Введите день недели:');
console.log(days[input]);
}
number9();

function number10(a,b,c)
{
console.log(a+b+Number(c));
}
let secondPar = 25;
number10(5, secondPar, prompt('Введите 3 параметр:') );

// function params(a,b)
// {
//     if(a === b)
//     {
//         return 4*a;
//     }
//     else
//     {
//         return a*b;
//     }

// }
// console.log(params(5,10));

// var params =function(a,b)
// {
//     if(a === b)
//     {
//         return 4*a;
//     }
//     else
//     {
//         return a*b;
//     }

// }
// console.log(params(5,10));

let paramsArray = (a,b) => (a === b) ? 4*a : a*b;
console.log(paramsArray(5,10));