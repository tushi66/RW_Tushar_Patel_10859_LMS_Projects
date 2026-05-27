function validateForm() {

    var taskName = document.querySelector('.inputname').value;
    var taskDescription = document.querySelector('.inputdescription').value;
    var dueDate = document.querySelector('.inputduedate').value;
    var priority = document.querySelector('.inputpriority').value;
    var tasks = JSON.parse(localStorage.getItem('tasks')) || [];

    var errorName = document.getElementById('errorname');
    var errorDescription = document.getElementById('errordescription');
    var errorDueDate = document.getElementById('errorduedate');
    var errorPriority = document.getElementById('errorpriority');

    errorName.innerHTML = '';
    errorDescription.innerHTML = '';
    errorDueDate.innerHTML = '';
    errorPriority.innerHTML = '';

    if (taskName === '') {
        errorName.innerHTML = 'Task Name is required...';
        return false;

    }
    if (taskDescription === '') {
        errorDescription.innerHTML = 'Task Description is required...';
        return false;
    }
    if (dueDate === '') {
        errorDueDate.innerHTML = 'Due Date is required...';
        return false;
    } else {
        var today = new Date();
        var selectedDate = new Date(dueDate);
        if (selectedDate < today) {
            errorDueDate.innerHTML = 'Due Date cannot be in the past...';
            return false;
        }

    }

    if (priority === '') {
        errorPriority.innerHTML = 'Priority is required...';
        return false;
    }


    return true;

}

function addTask() {
    if (validateForm()) {

        var taskName = document.querySelector('.inputname').value;
        var taskDescription = document.querySelector('.inputdescription').value;
        var dueDate = document.querySelector('.inputduedate').value;
        var priority = document.querySelector('.inputpriority').value;
        var tasks = JSON.parse(localStorage.getItem('tasks')) || [];

        var task = {
            name: taskName,
            description: taskDescription,
            dueDate: dueDate,
            priority: priority
        };

        tasks.push(task);

        localStorage.setItem('tasks', JSON.stringify(tasks));
        alert('Task added successfully!');

    }

    displayTasks();

}

function displayTasks() {

    var taskTableBody = document.getElementById('taskTableBody');

    var tasks = JSON.parse(localStorage.getItem('tasks')) || [];
  
    console.log('Displaying tasks...' + tasks);

    taskTableBody.innerHTML = '';



    tasks.forEach(function (task, index) {

        taskTableBody.innerHTML += `
        
            <th scope="row">${index + 1}</th>
            <td>${task.name}</td>
            <td>${task.description}</td>
            <td>${task.dueDate}</td>
            <td>${task.priority}</td>
        `;     

    });

}


function editTask(index) {

    var tasks = JSON.parse(localStorage.getItem('tasks')) || [];
    var task = tasks[index];

    document.getElementById('editIndex').value = index;
    document.getElementById('editName').value = task.name;
    document.getElementById('editDescription').value = task.description;
    document.getElementById('editDueDate').value = task.dueDate;
    document.getElementById('editPriority').value = task.priority;

    var modal = new bootstrap.Modal(document.getElementById('editModal'));
    modal.show();
    
}

function updateTask() {

    var index = document.getElementById('editIndex').value;

    var tasks = JSON.parse(localStorage.getItem('tasks')) || [];

    tasks[index].name = document.getElementById('editName').value;
    tasks[index].description = document.getElementById('editDescription').value;
    tasks[index].dueDate = document.getElementById('editDueDate').value;
    tasks[index].priority = document.getElementById('editPriority').value;

    localStorage.setItem('tasks', JSON.stringify(tasks));

    displayTasks();

    var modalEl = document.getElementById('editModal');
    var modal = bootstrap.Modal.getInstance(modalEl);
    modal.hide();
}

function deleteTask(index) {

    var tasks = JSON.parse(localStorage.getItem('tasks')) || [];

    tasks.splice(index, 1);

    localStorage.setItem('tasks', JSON.stringify(tasks));

    displayTasks();

}

displayTasks();




