# First Note to HTML



| tag          |  describtion |
| --- | --- |
| h1       | heading |
| p        | paragraph    |
| pre     | preserving white space |
| a       | attribute    |
| del | defines text that has been deleted |
| ins | text underline |
| hr | horizontal rule |
| em | emphasized text |
| i | italic text | 
| small | small text |
| b | bold |



<div align="center">
    <img src="https://github.com/kiaky0/Programming/assets/109141627/f0f311d1-abe3-45d4-8d31-64374ae1cdb4" width="700px">
</div>

<br>

## Table and list


Unorder List

```html
<ul>
           <li>Coffee</li>
           <li>Tea</li>
           <li>Milk</li>
</ul>

```

Order list

```html
<ol>
     <li>Coffee</li>
     <li>Tea</li>
     <li>Milk</li>
 </ol>
```

Order list with start and type attributes

```html
<ol start="10" type="A">
           <li>Coffee</li>
           <li>Tea</li>
           <li>Milk</li>
</ol>
```

Description List

```
<dl> tag defines the description list. 
<dt> defines terms/names 
<dd> describes each term/name
```

Example

```html
<dl>
   <dt>Milk</dt>
   <dd>A white color cold drink</dd>
   <dt>Coca ColaM</dt>
    <dd>A dark brown color soft/fizzy drink</dd>
</dl>
```

- result

<dl>
   <dt>Milk</dt>
   <dd>A white color cold drink</dd>
   <dt>Coca ColaM</dt>
    <dd>A dark brown color soft/fizzy drink</dd>
</dl>

<br>

## Table

- `<td>` ---> table data
- `<tr>` ---> table row
- `<td>` ---> table head

-  `colspan`  ---> column take
-  `rowspan`  ---> row take

Example

```html
<table>
  <tr>
    <th>Data 1</th>
    <th style="background-color: yellow">Data 2</th>
  </tr>
  <tr>
    <td>Calcutta</td>
    <td style="background-color: yellow">Orange</td>
  </tr>
  <tr>
    <td>Robots</td>
    <td style="background-color: yellow">Jazz</td>
  </tr>
</table>

```

- Output

<table>
  <tr>
    <th>Data 1</th>
    <th style="background-color: yellow">Data 2</th>
  </tr>
  <tr>
    <td>Calcutta</td>
    <td style="background-color: yellow">Orange</td>
  </tr>
  <tr>
    <td>Robots</td>
    <td style="background-color: yellow">Jazz</td>
  </tr>
</table>


<br>

## Linking

- a web page or location within a web page
- a file
- an e-mail address


```html
<a href ="http://www.facebook.com">Facebook</a>
<a href = "mailto:salsalbilal@utar.edu.my">UTAR EMAIL</a>
```

<br>

## Image

```html
<img
  src="images/dinosaur.jpg"
  alt="The head and torso of a dinosaur skeleton;
          it has a large head with long sharp teeth"
  width="400"
  height="341" />
```

```html
<h1>Images in HTML</h1>

<img
  src="dinosaur.jpg"
  alt="The head and torso of a dinosaur skeleton; it has a large head with long sharp teeth"
  title="A T-Rex on display in the Manchester University Museum" />
<blockquote>
  <p>
    But down there it would be dark now, and not the lovely lighted aquarium she
    imagined it to be during the daylight hours, eddying with schools of tiny,
    delicate animals floating and dancing slowly to their own serene currents
    and creating the look of a living painting. That was wrong, in any case. The
    ocean was different from an aquarium, which was an artificial environment.
    The ocean was a world. And a world is not art. Dorothy thought about the
    living things that moved in that world: large, ruthless and hungry. Like us
    up here.
  </p>
  <footer>- Rachel Ingalls, <cite>Mrs. Caliban</cite></footer>
</blockquote>

```

As soon as the browser downloads the HTML, the browser will start to display the page.

Once the image is loaded, the browser adds the image to the page. Because the image takes up space, the browser has to move the text down the page, to fit the image above it:



<img align="centre" src="https://github.com/kiaky0/Programming/assets/109141627/ebe35ac7-3b80-4d2b-8095-11add000b5d1">

<br>

## Special character

<img align="centre" src="https://github.com/kiaky0/Programming/assets/109141627/b0f862e6-b0e8-4133-94b5-c52099b6c414">


## Some tag 

```html
This is <b>bold</b> text
This is <em>emphasized</em> text
This is <i>italic</i> text
This is <small>small</small> text
This is <strong>strong</strong> text
This is <sub>sub</sub> text
This is <sup>sup</sup> text
This is <ins>ins<ins/> text
This is <del>del</del> text
```

This is <b>bold</b> text <br>
This is <em>emphasized</em> text <br>
This is <i>italic</i> text <br>
This is <small>small</small> text <br>
This is <strong>strong</strong> text <br>
This is <sub>sub</sub> text <br>
This is <sup>sup</sup> text <br> 
This is <ins>ins<ins/> text <br>
This is <del>del</del> text <br>











