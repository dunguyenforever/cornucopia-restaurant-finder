<template>
    <div id="app">
      <nav>
        <ul>
          <li><a href="#">Home</a></li>
          <li><a href="#">About</a></li>
          <li><a href="#" @click.prevent="showModal = true">Sign In</a></li>
        </ul>
      </nav>
      <SignInModal v-if="showModal" @close="showModal = false" />
    </div>
  </template>
  
  <script>
  import SignInModal from './components/SignInModal.vue'
  
  export default {
    name: 'App',
    components: {
      SignInModal
    },
    data() {
      return {
        showModal: false
      }
    }
  }
  </script>
  
  <style>
  /* Add your styles here */
  </style>
  