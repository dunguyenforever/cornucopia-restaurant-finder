<template>
    <nav :class="[`navbar-${theme}`, `bg-${theme}`, 'navbar', 'navbar-expand-lg']">
      <div class="container-fluid">
        <a href="#" class="navbar-brand">Cornucopia</a>
        <ul class="navbar-nav me-auto mb-2 mb-lg-0">
          <li v-for="(page, index) in pages" class="nav-items" :key="index">
            <a
              class="nav-link"
              :active="{ active: activePage == index }"
              aria-current="page"
              :href="page.link.url"
              :title="`This link goes to the ${page.link.text} page`"
              @click.prevent="navLinkClick(index)"
            >{{ page.link.text }}</a>
          </li>
          <button
            href="#"
            @click.stop="showModal = true"
            class="btn sign-in-btn"
          >
            Sign In
          </button>
        </ul>
      </div>
      <sign-in-modal :show-modal="showModal" @close-modal="showModal = false" />
    </nav>
  </template>
  
  <script>
  import SignInModal from "./SignInModal.vue";
  
  export default {
    name: "navbar",
    components: {
      SignInModal,
    },
    props: ["pages", "activePage", "navLinkClick"],
    data() {
      return {
        theme: "light",
        showModal: false,
      };
    },
    methods: {},
  };
  </script>
  