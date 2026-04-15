/* ============================================================
   QuRAC — Main JavaScript
   Follows the pattern of script.js from laltu-sardar.github.io
   ============================================================ */

/* ---- Mobile nav toggle (same pattern as personal site) ---- */
function toggleMenu() {
    const navUl = document.querySelector('header.site-header nav ul');
    if (navUl) navUl.classList.toggle('active');
}

/* ---- Image slider (same logic as personal site) ---- */
(function initSlider() {
    const sliders = document.querySelectorAll('.image-slider');
    sliders.forEach(function (slider) {
        const slides = slider.querySelectorAll('img');
        if (slides.length < 2) return;
        let current = 0;

        // auto-advance
        const timer = setInterval(function () {
            slides[current].classList.remove('active');
            current = (current + 1) % slides.length;
            slides[current].classList.add('active');
        }, 3200);

        // next/prev buttons scoped to this slider
        const prevBtn = slider.querySelector('.slider-btn.prev');
        const nextBtn = slider.querySelector('.slider-btn.next');

        if (nextBtn) {
            nextBtn.addEventListener('click', function () {
                slides[current].classList.remove('active');
                current = (current + 1) % slides.length;
                slides[current].classList.add('active');
            });
        }
        if (prevBtn) {
            prevBtn.addEventListener('click', function () {
                slides[current].classList.remove('active');
                current = (current - 1 + slides.length) % slides.length;
                slides[current].classList.add('active');
            });
        }
    });
})();

/* ---- Mark active nav link ---- */
(function markActive() {
    const page = window.location.pathname.split('/').pop() || 'qurac.html';
    document.querySelectorAll('header.site-header nav ul li a').forEach(function (link) {
        const href = (link.getAttribute('href') || '').split('/').pop();
        if (href === page) link.classList.add('active');
    });
})();
