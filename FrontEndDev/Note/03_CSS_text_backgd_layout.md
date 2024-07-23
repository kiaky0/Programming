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
  <li>Horizontal offset of the shadow: +ve value the box shadow will appear to left. -ve value the box shadow appear to the right </li>
  <li>Vertical offset of the shadow: -ve shadow move up. -ve the shadow move down</li>
  <li>Blur radius: 0px will result in sharp edge. The greater the value the more the edges of the shadow are blurred</li>
  <li>Color: The box-shadow color</li>
</ol>

## Linear gradient

```html
<!DOCTYPE html>
<html>
<head>
<style>
#grad1 {
  height: 200px;
  background-color: red; /* For browsers that do not support gradients */
  background-image: linear-gradient(red, yellow);
}
</style>
</head>
<body>

<h1>Linear Gradient - Top to Bottom</h1>
<p>This linear gradient starts red at the top, transitioning to yellow at the bottom:</p>

<div id="grad1"></div>

</body>
</html>
```
![image](https://github.com/user-attachments/assets/08bafb87-bccd-4c96-98d0-192ba87c5a2f)


[learn more](https://www.w3schools.com/css/css3_gradients.asp)


## Radial Gradient

```html
#grad1 {
  height: 150px;
  width: 200px;
  background-color: red; /* For browsers that do not support gradients */
  background-image: radial-gradient(red 5%, yellow 15%, green 60%);
}
```

![image](https://github.com/user-attachments/assets/9067df01-8845-43c0-9b33-b30ae2babb26)


## Text Stroke

```html
        h1{
            color: aquamarine;
            -webkit-text-stroke: 1px black;
        }
```

![image](https://github.com/user-attachments/assets/09c23340-6f19-4959-a940-79319a06d10e)

<br>

## CSS Animation

- @keyframes
- animation-name
- animation-duration
- animation-delay
- animation-iteration-count
- animation-direction
- animation-timing-function
- animation-fill-mode
- animation


```html
<!DOCTYPE html>
<html>
<head>
<style> 
div {
  width: 100px;
  height: 100px;
  background-color: red;
  animation-name: example;
  animation-duration: 4s;
}

@keyframes example {
  from {background-color: red;}
  to {background-color: yellow;}
}
</style>
</head>
<body>

<h1>CSS Animation</h1>

<div></div>

<p><b>Note:</b> When an animation is finished, it goes back to its original style.</p>

</body>
</html>

```

Animation is 25% complete, 50%, 75%, 100%

```html
<style>
div {
  width: 100px;
  height: 100px;
  background-color: red;
  animation-name: example;
  animation-duration: 4s;
}

@keyframes example {
  0%   {background-color: red;}
  25%  {background-color: yellow;}
  50%  {background-color: blue;}
  100% {background-color: green;}
}
</style>
```

delay 2 second starting the animation

```html
div {
  width: 100px;
  height: 100px;
  position: relative;
  background-color: red;
  animation-name: example;
  animation-duration: 4s;
  animation-delay: 2s;
}
```

animation-iteration-count: infinite;   ---> the animation will run infinitely

```html
  animation-iteration-count: 2;
  animation-direction: alternate;
```

- `animation-direction: alternate` : the animation will runforward and then backward

[learn more](https://www.w3schools.com/css/css3_animations.asp）


## CSS Transition

- transition
- transition-delay
- transition-duration
- transition-property
- transition-timing-function


```html
<style> 
div {
  width: 100px;
  height: 100px;
  background: red;
  transition: width 2s;
}

div:hover {
  width: 300px;
}
</style>
```

`transition-delay: 1s;` : delay the starting time of the transition






