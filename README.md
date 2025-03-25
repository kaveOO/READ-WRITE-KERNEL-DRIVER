<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a id="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
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

[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://en.wikipedia.org/wiki/Protection_ring">
    <img src="https://cdn.ezo.io/wp-content/uploads/2024/08/image-1-1024x1024.png" alt="Logo" width="200" height="200">
  </a>

<h3 align="center">Read/Write - Kernel Driver</h3>

  <p align="center">
    A simple Kernel Driver that remove Flash Duration on CS2 !
    <br>
    <br />
    <a href="https://github.com/kaveOO/ReadWriteKernel">View Demo</a>
    &middot;
    <a href="https://github.com/kaveOO/ReadWriteKernel/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    &middot;
    <a href="https://github.com/kaveOO/ReadWriteKernel/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#disclaimer">Disclaimer</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

[![Product Name Screen Shot][product-screenshot]](https://www.geeksforgeeks.org/kernel-in-operating-system/)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

* [![C][C]][C-url]
* [![C++][C++]][C++-url]
* [![VisualStudio][VisualStudio]][VisualStudio-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>


## Disclaimer

⚠️***Of course, in this Driver, I'm not using methods to Bypass the Anti-Cheat of CS2***
<br>
***Be sure to follow steps to not get your Account Banned, I'm not responsible of this !***
<br>
***Don't ask me how to bypass VAC, learn by yourself like all the GOATS of this World did***⚠️

<p align="right">(<a href="#disclaimer">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

If you want to use the Driver please read below.
<br>
Please do not open Issues for nothing don't be DUMB.
<br>
<br>
`GOOGLE IS YOUR FRIEND !`

### Prerequisites

This step is mandatory if you want to use the Driver !
* Install [Visual Studio](https://visualstudio.microsoft.com/)
* Install [Windows SDK](https://developer.microsoft.com/en-us/windows/downloads/windows-sdk/) 
* Libraries (Visual Studio Installer)
  ```sh
  MSVC v143 - VS 2022 C++ ARM64/ARM64EC Spectre-mitigated libs (Latest)
  MSVC v143 - VS 2022 C++ x64/x86 Spectre-mitigated libs (Latest)
  C++ ATL for latest v143 build tools with Spectre Mitigations (ARM64/ARM64EC)
  C++ ATL for latest v143 build tools with Spectre Mitigations (x86 & x64)
  C++ MFC for latest v143 build tools with Spectre Mitigations (ARM64/ARM64EC)
  C++ MFC for latest v143 build tools with Spectre Mitigations (x86 & x64)
  Windows Driver Kit
  ```

### Installation
⚠️ **Execute all commands in Elevated Command Prompt !**

2. Clone the repo
   ```sh
   git clone https://github.com/kaveOO/ReadWriteKernel.git
   ```
3. Build the project
   ```sh
   open ReadWriteKernel.sln and build the project in x64 Release
   ```
4. Setup Kernel Space
   ```
   bcdedit /set testsigning on
   bcdedit /debug on
   bcdedit /dbgsettings local
   ```
5. Restart your computer
6. Add Driver into Windows Kernel Space and start it
   ```
   sc create driver_name type=kernel binpath="path_to_driver" (path including driver .sys file !)
   sc start driver_name
   ```
7. Add Insecure flag in CS2 launch options ⚠️ THIS STEP IS MANDATORY ⚠️
   ```
   right click CS2 go to properties and add in launch options ->
   
   -insecure
   ```
8. Start CS2 and go to Private Match
9. Start Usermode Application (anti-flash)
   ```
   go to ReadWriteKernel\ReadWriteKernel\x64\Release
   run ReadWriteController.exe as Elevated Mode
   ```
10. Stop and delete Driver
   ```
  sc stop <driver_name>
  sc delete <driver_name>
   ```
11. Restart your computer
### NOW, YOU ARE A CHEATER GGWP 🧌
   
<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES
## Usage

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://example.com)_

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [x] Basic Functions of Driver
- [x] IOCTL Communication
- [x] Read/Write functions
- [x] IOCTL requests for Read/Write
- [x] Implementation of CS2 anti-flash
<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Top contributors:

<a href="https://github.com/kaveOO/ReadWriteKernel/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=kaveOO/ReadWriteKernel" alt="contrib.rocks image" />
</a>



<!-- LICENSE -->
## License

Distributed under the **MIT**. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT
## Contact

Your Name - [@kaveofps](https://twitter.com/kaveofps) - email@email_client.com

Project Link -> [https://github.com/kaveOO/ReadWriteKernel](https://github.com/kaveOO/ReadWriteKernel)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [Unknowns Cheats Forum](https://www.unknowncheats.me/forum/index.php)
* [Elitepvpers Forum](https://www.elitepvpers.com/)
* [Microsoft Kernel Documentation](https://learn.microsoft.com/en-us/windows-hardware/drivers/ddi/_kernel/)
* [Geeks For Geeks](https://www.geeksforgeeks.org/)
* [Amit Moshel (GOATED)](https://medium.com/@amitmoshel70)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[stars-shield]: https://img.shields.io/github/stars/kaveOO/ReadWriteKernel.svg?style=for-the-badge
[stars-url]: https://github.com/kaveOO/ReadWriteKernel/stargazers
[issues-shield]: https://img.shields.io/github/issues/kaveOO/ReadWriteKernel.svg?style=for-the-badge
[issues-url]: https://github.com/kaveOO/ReadWriteKernel/issues
[product-screenshot]: https://upload.wikimedia.org/wikipedia/commons/thumb/8/8f/Kernel_Layout.svg/1280px-Kernel_Layout.svg.png
[C]: https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white
[C-url]: https://en.wikipedia.org/wiki/C_(programming_language)
[C++]: https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white
[C++-url]: https://en.wikipedia.org/wiki/C%2B%2B
[VisualStudio]: https://img.shields.io/badge/Visual%20Studio-5C2D91.svg?style=for-the-badge&logo=visual-studio&logoColor=white
[VisualStudio-url]: https://visualstudio.microsoft.com/
