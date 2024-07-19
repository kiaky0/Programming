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

Using class for embedded css

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











