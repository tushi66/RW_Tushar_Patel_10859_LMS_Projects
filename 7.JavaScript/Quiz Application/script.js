/* Quiz App */
/* Questions Array */

const Questions = [
    {
        question: "Which keyword is used to describe a variable in javascript.",
        options: ["var", "int", "string", "define"],
        answer: 0
    },
    {
        question: "Which function is used to serialize an object into JSON string?",
        options: ["stringify()", "parse()", "convert()", "None"],
        answer: 0
    },
    {
        question: "Which of the following are closures in Javascript?",
        options: ["Variable", "Function", "Object", "All of the above"],
        answer: 3
    },
    {
        question: "Which is not a Javascript framework?",
        options: ["Node", "Vue", "React", "Cassandra"],
        answer: 3
    },
    {
        question: "Which method is used to access HTML elements?",
        options: ["getElementById()", "getElementByClassName()", "Both A and B", "None"],
        answer: 2
    },
    {
        question: "Which symbol is used for comments in JavaScript?",
        options: ["//", "/* */", "#", "<!-- -->"],
        answer: 0
    },
    {
        question: "Which method is used to convert JSON to a JavaScript object?",
        options: ["JSON.parse()", "JSON.stringify()", "JSON.convert()", "JSON.toObject()"],
        answer: 0
    },
    {
        question: "Which keyword is used to declare a constant in JavaScript?",
        options: ["var", "let", "const", "constant"],
        answer: 2
    },
    {
        question: "What will typeof null return in JavaScript?",
        options: ["null", "object", "undefined", "number"],
        answer: 1
    },
    {
        question: "Which method is used to add an element at the end of an array?",
        options: ["push()", "pop()", "shift()", "unshift()"],
        answer: 0
    }

]

/* Variables */

let timeRemaining = 300;
let currentQuestion = 0;
let selectedAnswer = null;
let score = 0;
let timeInterval;

/* DOM */

const startContainer = document.getElementById("startContainer");
const startBtn = document.getElementById("startBtn");

const quizBody = document.getElementById("quizBody");
const questionCounter = document.getElementById("questionCounter");
const nextBtn = document.getElementById("nextBtn");
const progressBar = document.getElementById("progressBar");
const timer = document.getElementById("timer");
const resultsContainer = document.getElementById("resultsContainer");
const restartBtn = document.getElementById("restartBtn");

/* Init */

const initQuizApp = () => {
    timeRemaining = 300;
    currentQuestion = 0;
    score = 0;
    selectedAnswer = null;

    resultsContainer.style.display = "none";
    document.getElementById("quizContainer").style.display = "block";

    clearInterval(timeInterval);
    startTimer();
    showQuestion();
    updateTimerDisplay();
};

/* Timer */

const startTimer = () => {
    clearInterval(timeInterval);

    timeInterval = setInterval(() => {
        timeRemaining--;
        updateTimerDisplay();

        if (timeRemaining <= 0) {
            clearInterval(timeInterval);
            endQuiz();
        }
    }, 1000);
}

const updateTimerDisplay = () => {
    const min = Math.floor(timeRemaining / 60);
    const sec = timeRemaining % 60;

    timer.textContent = `${min.toString().padStart(2, "0")}:${sec.toString().padStart(2, "0")}`;
}

// Start quiz

startBtn.addEventListener("click", () => {
    startContainer.style.display = "none";
    initQuizApp();
});

// Show question

const showQuestion = () => {
    const current = Questions[currentQuestion];

    document.getElementById("question").textContent = current.question;
    questionCounter.textContent = `${currentQuestion + 1} / ${Questions.length}`;

    quizBody.innerHTML = "";

    current.options.forEach((option, index) => {
        const btn = document.createElement("button");
        btn.classList.add("answer-option");
        btn.textContent = option;

        btn.onclick = () => selectAnswer(index, btn);

        quizBody.appendChild(btn);
    });

    nextBtn.disabled = true;

    updateProgressBar();
};

const selectAnswer = (index, btn) => {
    selectedAnswer = index;

    const options = document.querySelectorAll(".answer-option");

    options.forEach(option => {
        option.classList.remove("selected");

    });


    btn.classList.add("selected");

    nextBtn.disabled = false;
};

nextBtn.addEventListener("click", () => {

    if (selectedAnswer === null) {
        alert("Please select an answer!");
        return;
    }

    const options = document.querySelectorAll(".answer-option");

    options.forEach((btn, index) => {

        if (index === Questions[currentQuestion].answer) {
            btn.classList.add("correct");
        }

        if (index === selectedAnswer && index !== Questions[currentQuestion].answer) {
            btn.classList.add("incorrect");
        }
    });

    if (selectedAnswer === Questions[currentQuestion].answer) {
        score++;
    }

    setTimeout(() => {
        currentQuestion++;
        selectedAnswer = null;

        if (currentQuestion < Questions.length) {
            showQuestion();
        } else {
            endQuiz();
        }
    }, 800);
});


const updateProgressBar = () => {
    const progress = ((currentQuestion + 1) / Questions.length) * 100;
    progressBar.style.width = `${progress}%`;
};


const endQuiz = () => {
    clearInterval(timeInterval);

    document.getElementById("quizContainer").style.display = "none";
    resultsContainer.style.display = "block";

    document.getElementById("finalScore").textContent = `${score}/${Questions.length}`;
    document.getElementById("correctCount").textContent = score;
    document.getElementById("incorrectCount").textContent = Questions.length - score;
    document.getElementById("totalQuestions").textContent = Questions.length;
    document.getElementById("timeTaken").textContent = `${300 - timeRemaining}s`;


    const message = document.getElementById("resultsMessage");

    if (score === Questions.length) {
        message.textContent = "Perfect Score!";
    } else if (score >= Questions.length / 2) {
        message.textContent = "Good Job!";
    } else {
        message.textContent = "Keep Practicing";
    }
};


restartBtn.addEventListener("click", () => {
    resultsContainer.style.display = "none";
    document.getElementById("quizContainer").style.display = "none";
    startContainer.style.display = "flex";

    clearInterval(timeInterval);

});

/* Start */

// document.addEventListener("DOMContentLoaded", () => {

//     initQuizApp();

// })