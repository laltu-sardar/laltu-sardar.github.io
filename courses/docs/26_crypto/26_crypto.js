/* ============================================================
   COrgOS 2026 — JS Enhancements
   File: docs/26_data_security/26_ds.js
   ============================================================ */

(function () {
  'use strict';

  /* ── Marquee cursor tracker ── */
  const marquee = document.getElementById('marquee');
  if (marquee) {
    document.addEventListener('mousemove', function (e) {
      marquee.style.left = (e.pageX + 12) + 'px';
      marquee.style.top  = (e.pageY + 12) + 'px';
    });
  }

  /* ── Scroll-spy: highlight active nav link ── */
  const sections = document.querySelectorAll('[id]');
  const navLinks = document.querySelectorAll('.myNav ul li a');

  function onScroll() {
    let current = '';
    sections.forEach(sec => {
      if (window.scrollY >= sec.offsetTop - 80) current = sec.id;
    });
    navLinks.forEach(a => {
      a.classList.remove('nav-active');
      if (a.getAttribute('href') === ('#' + current) ||
          a.getAttribute('href').includes(current)) {
        a.classList.add('nav-active');
      }
    });
  }

  window.addEventListener('scroll', onScroll, { passive: true });

  /* ── Animate table rows on scroll ── */
  if ('IntersectionObserver' in window) {
    const rows = document.querySelectorAll('.table tbody tr');
    const rowObs = new IntersectionObserver((entries) => {
      entries.forEach((entry, i) => {
        if (entry.isIntersecting) {
          entry.target.style.animationDelay = (i * 0.03) + 's';
          entry.target.classList.add('row-visible');
          rowObs.unobserve(entry.target);
        }
      });
    }, { threshold: 0.1 });
    rows.forEach(row => {
      row.style.opacity = '0';
      row.style.transform = 'translateX(-10px)';
      row.style.transition = 'opacity 0.35s ease, transform 0.35s ease';
      rowObs.observe(row);
    });

    /* ── Section headings fade-in ── */
    const headings = document.querySelectorAll('h2, h3, h4');
    const hObs = new IntersectionObserver((entries) => {
      entries.forEach(entry => {
        if (entry.isIntersecting) {
          entry.target.style.opacity = '1';
          entry.target.style.transform = 'translateY(0)';
          hObs.unobserve(entry.target);
        }
      });
    }, { threshold: 0.15 });
    headings.forEach(h => {
      h.style.opacity = '0';
      h.style.transform = 'translateY(12px)';
      h.style.transition = 'opacity 0.5s ease, transform 0.5s ease';
      hObs.observe(h);
    });
  }

  /* ── "Row visible" helper ── */
  const styleTag = document.createElement('style');
  styleTag.textContent = `
    .row-visible { opacity: 1 !important; transform: none !important; }
    .nav-active { background: var(--amber) !important; color: var(--navy) !important; }
  `;
  document.head.appendChild(styleTag);

  /* ── Smooth back-to-top ── */
  const topBtn = document.querySelector('.js-back-to-top');
  if (topBtn) {
    topBtn.addEventListener('click', function (e) {
      e.preventDefault();
      window.scrollTo({ top: 0, behavior: 'smooth' });
    });
    window.addEventListener('scroll', function () {
      topBtn.style.opacity = window.scrollY > 300 ? '1' : '0';
      topBtn.style.pointerEvents = window.scrollY > 300 ? 'auto' : 'none';
    }, { passive: true });
    topBtn.style.opacity = '0';
    topBtn.style.transition = 'opacity 0.3s';
  }

})();
