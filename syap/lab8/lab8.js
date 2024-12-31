let  user = {
    name: 'Masha',
    age: 21
};
let numbers = [1, 2, 3];
let user1 = {
    name: 'Masha',
    age: 23,
    location: {
        city: 'Minsk',
        country: 'Belarus'
    }
};
let user2 = {
    name: 'Masha',
    age: 28,
    skills: ["HTML", "CSS", "JavaScript", "React"]
};
const array = [
    {id: 1, name: 'Vasya', group: 10}, 
    {id: 2, name: 'Ivan', group: 11},
    {id: 3, name: 'Masha', group: 12},
    {id: 4, name: 'Petya', group: 10},
    {id: 5, name: 'Kira', group: 11},
]
let user4 = {
    name: 'Masha',
    age: 19,
    studies: {
        university: 'BSTU',
        speciality: 'designer',
        year: 2020,
        exams: {
            maths: true,
            programming: false
        }
    }
};
let user5 = {
    name: 'Masha',
    age: 22,
    studies: {
        university: 'BSTU',
        speciality: 'designer',
        year: 2020,
        department: {
            faculty: 'FIT',
            group: 10,
        },
        exams: [
            { maths: true, mark: 8},
            { programming: true, mark: 4},
        ]
    }
};
let user6 = {
    name: 'Masha',
    age: 21,
    studies: {
        university: 'BSTU',
        speciality: 'designer',
        year: 2020,
        department: {
            faculty: 'FIT',
            group: 10,
        },
        exams: [
            { 
		maths: true,
		mark: 8,
		professor: {
		    name: 'Ivan Ivanov ',
		    degree: 'PDD'
		}
	     },
            { 
		programming: true,
		mark: 10,
		professor: {
		    name: 'Petr Petrov',
		    degree: 'PhD'
		}
	     },
        ]
    }
};
let user7 = {
    name: 'Masha',
    age: 20,
    studies: {
        university: 'BSTU',
        speciality: 'designer',
        year: 2020,
        department: {
            faculty: 'FIT',
            group: 10,
        },
        exams: [
            { 
                maths: true,
                mark: 8,
                professor: {
                    name: 'Ivan Petrov',
                    degree: 'PhD',
                    articles: [
                        {title: "About HTML", pagesNumber: 3},
                        {title: "About CSS", pagesNumber: 5},
                        {title: "About JavaScript", pagesNumber: 1},
                    ]
                }
            },
            { 
                programming: true,
                mark: 10,
                professor: {
                    name: 'Petr Ivanov',
                    degree: 'PhD',
                    articles: [
                        {title: "About HTML", pagesNumber: 3},
                        {title: "About CSS", pagesNumber: 5},
                        {title: "About JavaScript", pagesNumber: 1},
                    ]
                }
            },
        ]
    }
};
let store = {
    state: {
        profilePage: {
            posts: [
                {id: 1, message: 'Hi', likesCount: 12},
                {id: 2, message: 'By', likesCount: 1},
            ],
            newPostText: 'About me',
        },
        dialogPage: {
            dialogs: [
                {id: 1, name: 'Valera'},
                {id: 2, name: 'Andrey'},
                {id: 3, name: 'Sasha'},
                {id: 4, name: 'Victor'},
            ],
            messages: [
                {id: 1, message: 'hi'},
                {id: 2, message: 'hi hi'},
                {id: 3, message: 'hi hi hi'},
            ],
        },
        sidebar: [],
    },
}

//1
let userA = {...user};
let numbersA = {...numbers};
let user1A = {...user1, location: {...user1.location}};
let user2A = {...user2, skills: [...user2.skills]};
let arrayA = array.map( e => ({...e}));
let user4A = {...user4, studies: {...user4.studies, exams: {...user4.studies.exams}}};
let user5A = {...user5, studies: {...user5.studies, department: {...user5.studies.department}, exams: [...user5.studies.exams]}};
let user6A = {...user6, studies: {...user6.studies, department: {...user6.studies.department}, exams: user6.studies.exams.map(exam => ({...exam, professor: { ...exam.professor}}))}};
let user7A = { ...user7, studies: { ...user7.studies, department: { ...user7.studies.department }, exams: user7.studies.exams.map(exam => ({ ...exam, professor: { ...exam.professor, articles: exam.professor.articles.map(article => ({ ...article })) } })) }};
let storeA = { ...store, state: { ...store.state, profilePage: { ...store.state.profilePage, posts: store.state.profilePage.posts.map(post => ({ ...post })) }, dialogPage: { ...store.state.dialogPage, dialogs: store.state.dialogPage.dialogs.map(dialog => ({ ...dialog })), messages: store.state.dialogPage.messages.map(message => ({ ...message })) }, sidebar: [...store.state.sidebar] }};


//2
user5A.studies.group = 12;
user5A.studies.exams[1].mark = 10;
console.log(`Для копии user5: \n группа - ${user5A.studies.group} \n оценка - ${user5A.studies.exams[1].mark}`);


//3
user6A.studies.exams.forEach(e => {
    e.professor.name = "123";
    console.log(`\nНовое имя: ${e.professor.name}`);
});


//4
user7A.studies.exams[1].professor.articles[1].pagesNumber = 3;  
console.log(`Кол-во страниц для статьи “About CSS” преподавателя Petr Ivanov: ${user7A.studies.exams[1].professor.articles[1].pagesNumber}`);

//5
storeA.state.profilePage.posts.forEach(e => {
    e.message = "Hello";
});
console.log(storeA.state.profilePage.posts);



console.log(storeA.state.dialogPage.messages);
console.log(store.state.dialogPage.messages);