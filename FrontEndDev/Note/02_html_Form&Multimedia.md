# Content

- [Form](#Form)
- [Multimedia](#Multimedia)


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

<hr>

# Multimedia

```html
<!DOCTYPE html>
<html lang="en-US">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width">
    <title>Simple video example</title>
  </head>
  <body>
    <h1>Below is a simple video example</h1>

    <video src="rabbit320.webm" controls>
      <p>Your browser doesn't support HTML5 video. Here is a <a href="rabbit320.webm">link to the video</a> instead.</p> 
    </video>
  </body>
</html>
```

output

![image](https://github.com/user-attachments/assets/7e44cb15-3d20-43b0-a848-dc00e9164cbf)


Explaination:

_The paragraph inside the `<video>` tags._ This is called fallback content — this will be displayed if the browser accessing the page doesn't support the `<video>` element, allowing us to provide a fallback for older browsers. This can be anything you like; in this case, we've provided a direct link to the video file, so the user can at least access it some way regardless of what browser they are using.



Paragraph inside the video tag

```html
<video src="rabbit320.webm" controls>
  <p>
    Your browser doesn't support HTML video. Here is a
    <a href="rabbit320.webm">link to the video</a> instead.
  </p>
</video>

```

<br>

AutoPlay

```html
<video controls poster="video.jpg"
	width="160" height="150" autoplay loop>
	<source src="video.m4v" type="video/mp4">
	<source src="video.ogv" type="video/ogg">
	<a href="sparky.mov">Sparky the Dog</a>
</video>
```

<br>

More Video Feature

```html
<video
  controls
  width="400"
  height="400"
  autoplay
  loop
  muted
  preload="auto"
  poster="poster.png">
  <source src="rabbit320.mp4" type="video/mp4" />
  <source src="rabbit320.webm" type="video/webm" />
  <p>
    Your browser doesn't support this video. Here is a
    <a href="rabbit320.mp4">link to the video</a> instead.
  </p>
</video>

```

---> [Learn More Gate](https://developer.mozilla.org/en-US/docs/Learn/HTML/Multimedia_and_embedding/Video_and_audio_content#Other_video_features)

---> [Advance Audio and Video Delivery](https://developer.mozilla.org/en-US/docs/Web/Media/Audio_and_video_delivery)

---> [Multimedia and Embedding All](https://developer.mozilla.org/en-US/docs/Learn/HTML/Multimedia_and_embedding)
