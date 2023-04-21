<template>
    <div class="sign-in-modal" v-if="show">
      <div class="sign-in-modal-overlay" @click="close"></div>
      <div class="sign-in-modal-container">
        <div class="sign-in-modal-header">
          <h3>Sign In</h3>
          <button class="sign-in-modal-close" @click="close">
            <i class="fa fa-times"></i>
          </button>
        </div>
        <div class="sign-in-modal-body">
          <form>
            <div class="form-group">
              <label for="email">Email address</label>
              <input type="email" class="form-control" id="email" placeholder="Enter email">
            </div>
            <div class="form-group">
              <label for="password">Password</label>
              <input type="password" class="form-control" id="password" placeholder="Password">
            </div>
            <div class="form-group form-check">
              <input type="checkbox" class="form-check-input" id="remember-me">
              <label class="form-check-label" for="remember-me">Remember me</label>
            </div>
            <button type="submit" class="btn btn-primary">Sign In</button>
          </form>
        </div>
      </div>
    </div>
  </template>
  
  <script>
  export default {
    name: 'SignInModal',
    props: {
      show: {
        type: Boolean,
        default: false
      }
    },
    methods: {
      close() {
        this.$emit('close');
      }
    }
  }
  </script>
  
  <style scoped>
  .sign-in-modal {
    position: fixed;
    z-index: 999;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    display: flex;
    justify-content: center;
    align-items: center;
  }
  
  .sign-in-modal-overlay {
    position: absolute;
    z-index: 1;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    background-color: rgba(0, 0, 0, 0.5);
  }
  
  .sign-in-modal-container {
    position: relative;
    z-index: 2;
    max-width: 400px;
    width: 100%;
    padding: 30px;
    background-color: #fff;
    box-shadow: 0 0 10px rgba(0, 0, 0, 0.3);
  }
  
  .sign-in-modal-header {
    display: flex;
    justify-content: space-between;
    align-items: center;
    margin-bottom: 20px;
  }
  
  .sign-in-modal-close {
    background-color: transparent;
    border: none;
    font-size: 20px;
    color: #333;
    cursor: pointer;
  }
  
  .sign-in-modal-body {
    padding: 20px;
  }
  
  .form-group {
    margin-bottom: 20px;
  }
  
  .form-group label {
    display: block;
    margin-bottom: 5px;
    font-weight: bold;
  }
  
  .form-control {
    width: 100%;
    padding: 10px;
    border: 1px solid #ccc;
    border-radius: 5px;
    font-size: 16px;
  }
  
  .form-check-label {
    font-weight: normal;
  }
  
  .btn-primary {
    background-color: #007bff;
    border: none;
    border-radius: 5px;
    color: #fff;
    padding: 10px
  }

</style>