<template>
    <div>
      <h2>Sign In</h2>
      <form @submit.prevent="signIn">
        <label>
          Email:
          <input type="email" v-model="email" required>
        </label>
        <br>
        <label>
          Password:
          <input type="password" v-model="password" required>
        </label>
        <br>
        <button type="submit">Sign In</button>
      </form>
      <div v-if="error">{{ error }}</div>
    </div>
  </template>
  
<script>
export default {
data() {
    return {
    email: '',
    password: '',
    error: ''
    }
},
methods: {
    signIn() {
    // make API call to authenticate user
    // if successful, redirect to user's dashboard
    // if unsuccessful, display error message
    this.error = 'Invalid email or password';
    }
}
}
</script>