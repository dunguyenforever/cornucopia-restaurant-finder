<template>
  <section class="container">
    <div v-for="(card, index) in cards" :key="index" :style="{ zIndex: cards.length - index }">
      <Vue2InteractDraggable
        v-if="isVisible && index === currentIndex"
        :interact-out-of-sight-x-coordinate="500"
        :interact-max-rotation="15"
        :interact-x-threshold="200"
        :interact-y-threshold="200"
        @draggedRight="right"
        class="rounded-borders card"
      >
        <div class="flex flex--center" style="height: 100%">
          <h1>{{card.text}}</h1>
        </div>
      </Vue2InteractDraggable>
    </div>
  </section>
</template>

<script>
import { Vue2InteractDraggable } from 'vue2-interact'

export default {
  name: 'SwipeableCards',
  components: { Vue2InteractDraggable },
  data() {
    return {
      isVisible: true,
      currentIndex: 0,
      cards: [
        { text: 'one' },
        { text: 'two' },
        { text: 'three' },
        { text: 'four' },
        { text: 'five' },
      ]
    }
  },
  methods: {
    right() {
      setTimeout(() => {
        this.currentIndex++
        this.isVisible = true
      }, 300)
    }
  }
}
</script>

<style scoped>
.container {
  background: #eceff1;
  width: 100%;
  height: 100vh;
  position: relative;
}

.flex {
  display: flex;
}

.flex--center {
  align-items: center;
  justify-items: center;
  justify-content: center;
}

.rounded-borders {
  border-radius: 12px;
}

.card {
  width: 300px;
  height: 400px;
  color: white;
  position: absolute;
  left: 50%;
  transform: translate(-50%, -50%);
}

.card:nth-child(2) {
  background-color: pink;
  z-index: 2;
  top: 30px;
  width: 280px;
  height: 360px;
}

.card:nth-child(3) {
  background-color: red;
  z-index: 1;
  top: 60px;
  width: 260px;
  height: 320px;
}

.card:nth-child(4) {
  background-color: orange;
  z-index: 0;
  top: 90px;
  width: 240px;
  height: 280px;
}
</style>
