# CSS

## Inline CSS

```htnl
<body>
    <h1 style="font-size: 150%; width: 600px;">Header 1</h1>
    <h2 style="font-size: 130%;">Header2</h2>
    <p style="font-size: 100%;">this is paragraph</p>
    <br>
    <p style="background-color: yellow;">Inline style</p>
</body>
```

<br>

## Embedded CSS

![image](https://github.com/user-attachments/assets/155cd605-16bd-474f-8480-b3dd7c49c728)


```html
<head>
    <title>Exercise 2</title>
    <style>
        h1 {
            font-family: Arial, Helvetica, sans-serif;
            font-size: 18px;
            font-weight: bold;
            color: #996666;
            text-decoration: none;
        }
    </style>
</head>

<body>
    <h1>\This is header 1</h1>

</body>
```

<br>

Another Example

```html
<!DOCTYPE html>
<html>

<head>
    <style>
        body {
            background-color: lightblue;
        }

        h1 {
            color: white;
            text-align: center;
        }

        p {
            font-family: verdana;
            font-size: 20px;
        }
    </style>
</head>

<body>

    <h1>My First CSS Example</h1>
    <p>This is a paragraph.</p>

</body>

</html>
```

- output

![image](https://github.com/user-attachments/assets/f3e77cf9-339b-46f0-af05-e0b5299584ed)

### Class selector

```html
<head>
    <style type="text/css">
        .embeddedExample {
               background: orange;
         }
    </style>
</head>

<body>

    <p class="embeddedExample">Embedded style example 1 </p>
    <p class="embeddedExample">Embedded style example 2 </p>
</body>
```

- Another example

```html
<!DOCTYPE html>
<html>
<head>
<style>
.center {
  text-align: center;
  color: red;
}
</style>
</head>
<body>

<h1 class="center">Red and center-aligned heading</h1>
<p class="center">Red and center-aligned paragraph.</p> 

</body>
</html>
```

- output

![image](https://github.com/user-attachments/assets/86903f99-b897-4b9a-96b6-1ec549c578b2)



<br>

## External CSS

```html
<link rel="stylesheet" type="text/css" href="external-styles.css" />

<p id="externalExample">External style example</p>
```

Create CSS document “external-styles.css” that contains the following text: 

```css
#externalExample {
    background: green;
}
```

### Note

The <link> element can be used in an HTML document to tell the browser where to find the CSS file used to style the page. It is an empty element (meaning it does not need a closing tag), and it lives inside the <head> element. It should use three attributes: 

**href** ---> This specifies the path to the CSS file (which is often placed in a folder called css or styles). 

**type** ---> This attribute specifies the type of document being linked to. The value should be text/css. 

**rel**  ---> This specifies the relationship between the HTML page and the file it is linked to. The value should be stylesheet when linking to a CSS file.


<br>

## Selector

### 1. Universal selector

```html
<!DOCTYPE html>
<html>
<head>
<style>
* {
  text-align: center;
  color: blue;
}
</style>
</head>
<body>

<h1>Hello world!</h1>

<p>Every element on the page will be affected by the style.</p>
<p id="para1">Me too!</p>
<p>And me!</p>

</body>
</html>
```

### 2. Type/Tag Selector

```html
span {
            border: 10px solid red;
        }
```

- the span tag only will change

### 3. Class selector

```html
<style>
  .heading {
            color: green;
        }
</style>

<body>
    <h2 class="heading">H2 element</h2>
    <p class="heading">Para(p) element</p>
</body>

```

### 4. ID Selector

ID must be unique and only be used once

```html
<style>
    #liA {
                font-weight: bold;
            }
</style>

<body>
    <li id="liA"> List item(li) element</li>
</body?
```

### 5.	Descendant Selector

Selects all specified descendant child elements under the parent element.   

```html
#divA p {
            background-color: lightgreen;
        }
```

### 6. Child Selector

```html
   #divA > p {
            color: red;
        }
```

### 7. Adjacent Sibling Selectors

```html
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<title>Example of CSS Adjacent Sibling Selectors</title>
<style>
	h1 + p {
		color: blue;
		font-size: 18px;
	}
	ul.task + p {
		color: #f0f;
		text-indent: 30px;
	}
</style>
</head>
<body>
	<h1>This is a heading</h1>
	<p>This is a paragraph.</p>
	<p>This is another paragraph.</p>
	<ul class="task">
		<li>Task 1</li>
		<li>Task 2</li>
		<li>Task 3</li>
	</ul>
	<p>This is one more paragraph.</p>
	<p>This is also a paragraph.</p>
</body>
</html>

```

- result

![image](https://github.com/user-attachments/assets/f2251a86-de63-4296-a60c-8e6819a27966)


### 8. General Sibling Selectors

```html
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<title>Example of CSS General Sibling Selectors</title>
<style>
	h1 ~ p {
		color: blue;
		font-size: 18px;
	}
	ul.task ~ p {
		color: #f0f;
		text-indent: 30px;
	}
</style>
</head>
<body>
	<h1>This is a heading</h1>
	<p>This is a paragraph.</p>
	<p>This is another paragraph.</p>
	<ul class="task">
		<li>Task 1</li>
		<li>Task 2</li>
		<li>Task 3</li>
	</ul>
	<p>This is one more paragraph.</p>
	<p>This is also a paragraph.</p>
</body>
</html>

```

<br>

## CSS Box Model

![image](https://github.com/user-attachments/assets/092600f5-4f1d-4d06-aa23-aa4e2004a83d)


- Content - The content of the box, where text and images appear
- Padding - Clears an area around the content. The padding is transparent
- Border - A border that goes around the padding and content
- Margin - Clears an area outside the border. The margin is transparent

<br>

**Pading and Width**

```html
<!DOCTYPE html>
<html>
<head>
<style>
div.ex1 {
  width: 300px;
  background-color: yellow;
}

div.ex2 {
  width: 300px;
  padding: 25px;
  background-color: lightblue;
}
</style>
</head>
<body>

<h2>Padding and element width</h2>

<div class="ex1">This div is 300px wide.</div>
<br>

<div class="ex2">The width of this div is 350px, even though it is defined as 300px in the CSS.</div>

</body>
</html>
```

result

![image](https://github.com/user-attachments/assets/ccaade07-9b6e-4253-881f-685c9d51611b)



### Margin

- `margin-top`
- `margin-bottom`
- `margin-left`
- `margin-right`

<br>

Example

```html
<!DOCTYPE html>
<html>
<head>
<style>
div {
  border: 1px solid black;
  margin-top: 100px;
  margin-bottom: 100px;
  margin-right: 150px;
  margin-left: 80px;
  background-color: lightblue;
}
</style>
</head>
<body>

<h2>Using individual margin properties</h2>

<div>This div element has a top margin of 100px, a right margin of 150px, a bottom margin of 100px, and a left margin of 80px.</div>

</body>
</html>
```

result

![image](https://github.com/user-attachments/assets/41231c0b-2622-43f2-881e-7cbf78e92b56)

Note

if `margin: 25px 50px 75px 100px;`:

- top margin is 25px
- right margin is 50px
- bottom margin is 75px
- left margin is 100px


### Pading

```html
<!DOCTYPE html>
<html>
<head>
<style>
div {
  border: 1px solid black;
  background-color: lightblue;
  padding-top: 50px;
  padding-right: 30px;
  padding-bottom: 50px;
  padding-left: 80px;
}
</style>
</head>
<body>

<h2>Using individual padding properties</h2>

<div>This div element has a top padding of 50px, a right padding of 30px, a bottom padding of 50px, and a left padding of 80px.</div>

</body>
</html>
```

result

![image](https://github.com/user-attachments/assets/1e553934-a18e-4311-9e5e-8925944d61f4)


















