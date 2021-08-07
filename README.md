
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<p align="center">
  <!--<a href="https://github.com/Azzedine-prog/command-line-arguments-parser">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>-->

  <h3 align="center">Command line argument parser</h3>

  <p align="center">
    command line argument made easy , (just add arguments and methods for them and you are good to go).
    <br />
    <a href="https://github.com/Azzedine-prog/command-line-arguments-parser"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    ·
    <a href="https://github.com/Azzedine-prog/command-line-arguments-parser/issues">Report Bug</a>
    ·
    <a href="https://github.com/Azzedine-prog/command-line-arguments-parser/issues">Request Feature</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

[![Product Name Screen Shot][product-screenshot]](https://example.com)

this project is made to satisfy one goal : parsing command line arguments with little steps making your work with command line arguments easy and fast.

Here's why:
* Your time should be focused on creating something amazing. A project that solves a problem and helps others
* You shouldn't be doing the same tasks over and over like creating a README from scratch
* You should element DRY principles to the rest of your life :smile:

by forking this repo and creating a pull request or opening an issue.

A list of commonly used resources that I find helpful are listed in the acknowledgements.

<!--###Built With

This section should list any major frameworks that you built your project using. Leave any add-ons/plugins for the acknowledgements section. Here are a few examples.
* [Bootstrap](https://getbootstrap.com)
* [JQuery](https://jquery.com)
* [Laravel](https://laravel.com)



 GETTING STARTED -->
## Getting Started

check the test file where an example describing the work of this project.
which is easy 


## Usage

example of usage.
```c
	linked_list_string* my_arguments = argument_init();
	add_argument_with_help_and_action("add","a",1,INT,"this is for adding",&add,NULL,NULL,my_arguments);
	add_argument_with_help_and_action("version","v",0,BOOL,"this is for version",NULL,NULL,&version,my_arguments);
	add_argument_with_help_and_action("name","n",0,CHAR,"this is for printing name",NULL,&fun,NULL,my_arguments);
	manage_arguments(argc,argv,my_arguments);
```
example of methods.
```c
void add(int number){
	printf("that number is : %d \n",number);
}
void fun(char* mychar){
	printf("char string : %s\n",mychar);
}
void version(void){
	printf("this is version 15.0.2 \n open source library \n \t made by : A Z Z E D I N E  L A K H D A R \n");
}
```

## License

Distributed under the GNU License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

AZZEDINE LAKHDAR - [@AZZEDINE_AT_TWITTER](https://twitter.com/azzedinelakhdar) - aazzedinelakhdar@gmail.com

Project Link: [https://github.com/Azzedine-prog/command-line-arguments-parser](https://github.com/Azzedine-prog/command-line-arguments-parser)



<!-- ACKNOWLEDGEMENTS 
## Acknowledgements
* [GitHub Emoji Cheat Sheet](https://www.webpagefx.com/tools/emoji-cheat-sheet)
* [Img Shields](https://shields.io)
* [Choose an Open Source License](https://choosealicense.com)
* [GitHub Pages](https://pages.github.com)
* [Animate.css](https://daneden.github.io/animate.css)
* [Loaders.css](https://connoratherton.com/loaders)
* [Slick Carousel](https://kenwheeler.github.io/slick)
* [Smooth Scroll](https://github.com/cferdinandi/smooth-scroll)
* [Sticky Kit](http://leafo.net/sticky-kit)
* [JVectorMap](http://jvectormap.com)
* [Font Awesome](https://fontawesome.com)-->





<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/Azzedine-prog/command-line-arguments-parser.svg?style=for-the-badge
[contributors-url]: https://github.com/Azzedine-prog/command-line-arguments-parser/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Azzedine-prog/command-line-arguments-parser.svg?style=for-the-badge
[forks-url]: https://github.com/Azzedine-prog/command-line-arguments-parser/network/members
[stars-shield]: https://img.shields.io/github/stars/Azzedine-prog/command-line-arguments-parser.svg?style=for-the-badge
[stars-url]: https://github.com/Azzedine-prog/command-line-arguments-parser/stargazers
[issues-shield]: https://img.shields.io/github/issues/Azzedine-prog/command-line-arguments-parser.svg?style=for-the-badge
[issues-url]: https://github.com/Azzedine-prog/command-line-arguments-parser/issues
[license-shield]: https://img.shields.io/github/license/Azzedine-prog/command-line-arguments-parser.svg?style=for-the-badge
[license-url]: https://github.com/Azzedine-prog/command-line-arguments-parser/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/azzedine-lakhdar/
[product-screenshot]: images/project.png
