# Here are the resources for Hackathon


### Time monitoring function

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Web Usage Monitor</title>
    <style>
        body {
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            height: 100vh;
            margin: 0;
            font-family: Arial, sans-serif;
            background-color: #f0f0f0;
        }
        .container {
            text-align: center;
        }
        .timer {
            font-size: 48px;
            margin-bottom: 20px;
        }
        .controls {
            margin-bottom: 20px;
        }
        input, button {
            padding: 10px;
            margin: 5px;
            font-size: 16px;
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="timer" id="totalTime">Total Time: 00:00:00</div>
        <div class="controls">
            <input type="number" id="notificationTime" placeholder="Set time in minutes">
            <button id="setNotificationButton">Set Notification</button>
        </div>
        <div class="timer" id="countdownTimer">Countdown: 00:00:00</div>
        <div id="notification" style="color: red; font-size: 20px;"></div>
    </div>
    <script src="script.js"></script>
</body>
</html>

```

script.js

```js
// Get references to HTML elements
const totalTimeElement = document.getElementById('totalTime');
const countdownTimerElement = document.getElementById('countdownTimer');
const notificationElement = document.getElementById('notification');
const notificationTimeInput = document.getElementById('notificationTime');
const setNotificationButton = document.getElementById('setNotificationButton');

// Initialize variables
let startTime;
let totalTimeInterval;
let countdownInterval;
let countdownTime;
let countdownEndTime;
let notificationTimeout;

// Start the timer when the page loads
window.onload = () => {
    startTime = new Date();
    totalTimeInterval = setInterval(updateTotalTime, 1000);
};

// Update the total time display
function updateTotalTime() {
    const currentTime = new Date();
    const elapsedTime = currentTime - startTime;
    
    const hours = Math.floor(elapsedTime / 3600000);
    const minutes = Math.floor((elapsedTime % 3600000) / 60000);
    const seconds = Math.floor((elapsedTime % 60000) / 1000);
    
    totalTimeElement.textContent = `Total Time: ${pad(hours)}:${pad(minutes)}:${pad(seconds)}`;
}

// Pad single digit numbers with a leading zero
function pad(number) {
    return number < 10 ? '0' + number : number;
}

// Set a notification timer
setNotificationButton.addEventListener('click', () => {
    const minutes = parseInt(notificationTimeInput.value);
    if (isNaN(minutes) || minutes <= 0) {
        alert('Please enter a valid number of minutes.');
        return;
    }
    
    countdownTime = minutes * 60000; // Convert minutes to milliseconds
    countdownEndTime = new Date().getTime() + countdownTime;

    if (notificationTimeout) {
        clearTimeout(notificationTimeout); // Clear any existing notification timeout
    }
    if (countdownInterval) {
        clearInterval(countdownInterval); // Clear any existing countdown interval
    }
    
    notificationTimeout = setTimeout(() => {
        notificationElement.textContent = 'Time is up!';
        alert('Time is up!');
    }, countdownTime);
    
    countdownInterval = setInterval(updateCountdownTimer, 1000);
    notificationElement.textContent = '';
    alert(`Notification set for ${minutes} minutes.`);
});

// Update the countdown timer display
function updateCountdownTimer() {
    const currentTime = new Date().getTime();
    const remainingTime = countdownEndTime - currentTime;

    if (remainingTime <= 0) {
        clearInterval(countdownInterval);
        countdownTimerElement.textContent = `Countdown: 00:00:00`;
        return;
    }
    
    const hours = Math.floor(remainingTime / 3600000);
    const minutes = Math.floor((remainingTime % 3600000) / 60000);
    const seconds = Math.floor((remainingTime % 60000) / 1000);
    
    countdownTimerElement.textContent = `Countdown: ${pad(hours)}:${pad(minutes)}:${pad(seconds)}`;
}
```

Example output

![image](https://github.com/kiaky0/Programming/assets/109141627/e3372fdf-6399-47c0-bbf1-e189f1274a93)























