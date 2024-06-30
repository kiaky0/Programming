Creating a simple website with separate login pages for an admin and a user involves setting up HTML forms for login and then directing the user to their respective pages based on their credentials. For simplicity, this example will not include actual backend authentication, but will demonstrate how to structure the HTML and use JavaScript for client-side handling.

### 1. **Set Up the HTML Structure**

Create the main login page (`index.html`), the admin page (`admin.html`), and the user page (`user.html`).

#### `index.html`
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login Page</title>
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
        input, button {
            padding: 10px;
            margin: 5px;
            font-size: 16px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Login</h1>
        <form id="loginForm">
            <input type="text" id="username" placeholder="Username" required><br>
            <input type="password" id="password" placeholder="Password" required><br>
            <button type="submit">Login</button>
        </form>
        <div id="error" style="color: red; font-size: 16px;"></div>
    </div>
    <script src="login.js"></script>
</body>
</html>
```

#### `admin.html`
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin Page</title>
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
    </style>
</head>
<body>
    <div class="container">
        <h1>Welcome Admin</h1>
        <p>This is the admin page.</p>
    </div>
</body>
</html>
```

#### `user.html`
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>User Page</title>
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
    </style>
</head>
<body>
    <div class="container">
        <h1>Welcome User</h1>
        <p>This is the user page.</p>
    </div>
</body>
</html>
```

### 2. **Add JavaScript for Login Handling**

Create a JavaScript file (`login.js`) to handle the login logic.

#### `login.js`
```javascript
document.getElementById('loginForm').addEventListener('submit', function(event) {
    event.preventDefault();
    
    const username = document.getElementById('username').value;
    const password = document.getElementById('password').value;
    const errorElement = document.getElementById('error');

    // Simulated login logic
    if (username === 'admin' && password === 'admin123') {
        window.location.href = 'admin.html';
    } else if (username === 'user' && password === 'user123') {
        window.location.href = 'user.html';
    } else {
        errorElement.textContent = 'Invalid username or password';
    }
});
```

### Explanation

1. **HTML Structure:**
    - The `index.html` file contains a simple login form with fields for username and password.
    - The `admin.html` and `user.html` files are the respective pages for the admin and user.

2. **JavaScript Functionality:**
    - The `login.js` script adds an event listener to the login form.
    - When the form is submitted, it prevents the default form submission, retrieves the username and password, and performs a simple check.
    - If the credentials match the hardcoded admin or user credentials, it redirects to the appropriate page. Otherwise, it displays an error message.

### Running the Application

Save the HTML and JavaScript files in the same directory. Open the `index.html` file in your browser to see the login form. You can log in with the following credentials:

- Admin: `admin`, `admin123`
- User: `user`, `user123`

This basic implementation demonstrates the structure and client-side handling. For a real application, you would implement server-side authentication and secure the login process.
