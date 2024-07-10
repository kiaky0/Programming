# Form

## HTML input type

```html
<input type="button">
<input type="checkbox">
<input type="color">
<input type="date">
<input type="datetime-local">
<input type="email">
<input type="file">
<input type="hidden">
<input type="image">
<input type="month">
<input type="number">
<input type="password">
<input type="radio">
<input type="range">
<input type="reset">
<input type="search">
<input type="submit">
<input type="tel">
<input type="text">
<input type="time">
<input type="url">
<input type="week">
```

Example code

```html
<form action="/action_page.php">
  <label for="fname">First name:</label><br>
  <input type="text" id="fname" name="fname" value="John"><br>
  <label for="lname">Last name:</label><br>
  <input type="text" id="lname" name="lname" value="Doe"><br><br>
  <input type="submit" value="Submit">
</form> 

<p>If you click the "Submit" button, the form-data will be sent to a page called "/action_page.php".</p>
```

![image](https://github.com/kiaky0/Programming/assets/109141627/315a377c-b11a-4fe6-a0eb-5c2ead33f943)

<br>

## Target Attribute


| Value | Description |
| --- | --- |
| _blank | open in new tab |
| _self | open in current window |
| _parent | display in parent frame |
| _top | display in the full body of the window |
| framename | displayed in named iframe |

<br>

## Form Element

```html
<input>
<label>
<select>
<textarea>
<button>
<fieldset>
<legend>
<datalist>
<output>
<option>
<optgroup>
```

Example code

```html
<form action="/action_page.php">
  <label for="cars">Choose a car:</label>
  <select id="cars" name="cars">
    <option value="volvo">Volvo</option>
    <option value="saab">Saab</option>
    <option value="fiat">Fiat</option>
    <option value="audi">Audi</option>
  </select>
  <input type="submit">
</form>
```

![image](https://github.com/kiaky0/Programming/assets/109141627/78b52166-e3db-4233-9f0c-b68b4c41aba7)

More information: [W3 School](https://www.w3schools.com/html/html_form_elements.asp)

**HTML Form Element**

![image](https://github.com/kiaky0/Programming/assets/109141627/4bf62986-6920-4e06-96cd-09af660edf56)


<br>


