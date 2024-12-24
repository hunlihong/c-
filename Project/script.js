const bar = document.querySelector(".bar");
const navigation = document.querySelector(".nav-container");
const nav_list = document.querySelectorAll(".item");
const purpose = document.querySelectorAll(".purpose-img > i");
const choose_person = document.querySelector("select");
const majors = document.querySelectorAll(".each");
const each_major = document.querySelector(".each > h3");

const purpose_category = [
  {
    panel:
      "We want to share general knowledge about information technology and science to the world as the fundermental understanding.",
    background: "dodgerblue",
  },
  {
    panel:
      "We want to share what we study at university focusing on Infomation Technology(IT) major to juniors especially.",
    background: "gray",
  },
  {
    panel:
      "We want to be consultants and the IT map provider for people who study IT major for the future skills or occupations.",
    background: "red",
  },
  {
    panel:
      "We want to be the part of software development and setter for technology major evolution through what we have done, such this website.",
    background: "green",
  },
];
const person = [
  {
    name: "HUN LIHONG",
    profile: "image/lihong.jpg",
    job: "Front-End Developeer",
    languages: "C++, HTML, CSS, JavaScript",
  },
  {
    name: "HEAN LYHONG",
    profile: "image/lyhong.jpg",
    job: "Front-End Developeer",
    languages: "C++, HTML, CSS, JavaScript",
  },
  {
    name: "KAO MENGHORN",
    profile: "image/menghorn.jpg",
    job: "Mobile App Developeer",
    languages: "C++, HTML, CSS, JavaScript, Java, Flutter",
  },
  {
    name: "KHIN SAMBATH",
    profile: "image/sambath.jpg",
    job: "Front-End Developeer",
    languages: "C++, HTML, CSS, JavaScript",
  },
];

bar.addEventListener("click", () => {
  bar.classList.toggle("active");
  navigation.classList.toggle("active");
});

purpose.forEach((each) => {
  each.addEventListener("click", (click) => {
    const check = click.currentTarget.dataset.id;
    document.querySelector(".panel > p").innerHTML =
      purpose_category[check - 1].panel;
    document.querySelector(".panel").style.background =
      purpose_category[check - 1].background;
  });
});

choose_person.oninput = function () {
  const value = choose_person.value;
  for (let i = 0; i < person.length; i++) {
    if (person[i].name.toLowerCase().includes(value)) {
      document.querySelector(".name").innerHTML = person[i].name;
      document
        .querySelector(".profile-pic > img")
        .setAttribute("src", person[i].profile);
      document.querySelector(".job").innerHTML = `Job: ${person[i].job}`;
      document.querySelector(
        ".languages"
      ).innerHTML = `Languages: ${person[i].languages}`;
    }
  }
};
