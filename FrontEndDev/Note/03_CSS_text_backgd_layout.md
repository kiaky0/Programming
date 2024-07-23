# CSS Part II

## Text shadow

```html
h1 {
  text-shadow: -4px 4px 6px dimgrey;
  font-size: 400%
}
```

output

![image](https://github.com/user-attachments/assets/eac074ac-6d15-42f2-a2bf-9af33f3f6545)


## Adding round border

`border-radius:`

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Round Corner</title>
    <style type="text/css">
        div
        {
            border: 3px solid navy;
            padding: 5px 20px;
            background: lightcyan;
            width: 200px;
            text-align: center;
            border-radius: 15px; /*adding round corner */
            margin-bottom: 20px;
        }
        #round2
        {
            border: 3px solid navy;
            padding: 5px 20px;
            background: lightcyan;
            width: 200px;
            text-align: center;
            border-radius: 50px;
        }
    </style>
</head>
<body>
    <div>The border-radius property adds rounds corner to an element</div>
    <div id="round2">Increasing the border-radius rounds the corner of the element more</div>
</body>
</html>
```

![image](https://github.com/user-attachments/assets/41544d04-8cf0-4a23-a962-1d1cb6e16a98)


## Color

`background-color: `

property: hsl(hue,saturation,lightness)

```html
background-color: hsl(95, 57%, 55%);
```


## Box shadows

`box-shadow: 25px 25px 50px dimgrey;`

Property:

<ol type='I'>
  <li>**Horizontal offset of the shadow:** +ve value the box shadow will appear to left. -ve value the box shadow appear to the right </li>
  <li>**Vertical offset of the shadow:** -ve shadow move up. -ve the shadow move down</li>
  <li>**Blur radius:** 0px will result in sharp edge. The greater the value the more the edges of the shadow are blurred</li>
  <li>**Color:** The box-shadow color</li>
</ol>




















































































