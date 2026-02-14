function toggleMenu() {
    const nav = document.querySelector("nav ul");
    nav.classList.toggle("active");
}

/* Image slider */
const slides = document.querySelectorAll(".image-slider img");
let current = 0;

if (slides.length > 0) {
    setInterval(() => {
        slides[current].classList.remove("active");
        current = (current + 1) % slides.length;
        slides[current].classList.add("active");
    }, 3000);
}

function nextSlide() {
    slides[current].classList.remove("active");
    current = (current + 1) % slides.length;
    slides[current].classList.add("active");
}

function prevSlide() {
    slides[current].classList.remove("active");
    current = (current - 1 + slides.length) % slides.length;
    slides[current].classList.add("active");
}

