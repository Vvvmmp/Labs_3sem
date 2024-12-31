class Task{
    constructor(id, name, state = false){
        this.id = id;
        this.name = name;
        this.state = state;
    }

    renewName(newName){
        this.name = newName
        return this.name;
    }
    
    renewState(newStatus){
        this.state = newStatus;
        return this.state;
    }

}

class Todolist{
    constructor(id, name){
        this.id = id;
        this.name = name;
        this.tasks = [];
    }

    newName(newName){
        this.name = newName;
    }

    addTask(task) {
        this.tasks.push(task);
    }


    filterTasksByStatus(status) {
        return this.tasks.filter(task => task.state === status);
    }

    
}

const todolist1 = new Todolist(1, "todolist1");
const todolist2 = new Todolist(2, "todolist2");

const task1 = new Task(1, "Сделать сяп", false);
const task2 = new Task(2, "Написать кр", true);
const task3 = new Task(3, "Курсач", false);
//task1.renewName("сделять кяр");
//task1.renewState(true);
console.log(task1);
todolist1.addTask(task1);
todolist1.addTask(task2);
todolist2.addTask(task3);
todolist2.addTask(task2);


const completedTasks = todolist2.filterTasksByStatus(false);
completedTasks.forEach(task => console.log(`ID: ${task.id}, Name: ${task.name}`));