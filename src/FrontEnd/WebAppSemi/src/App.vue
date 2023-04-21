<template>
  <navbar 
        :pages="pages"
        :active-page = "activePage"
        :nav-link-click = "(index) => activePage = index"
  ></navbar>
  <page-viewer
        :page = "pages[activePage]"
  ></page-viewer>
</template>

<script>
import Navbar from './components/Navbar.vue'
import PageViewer from './components/PageViewer.vue'
import SignInModal from './components/SignInModal.vue'
import SwipeableCards from './components/SwipeableCards.vue'
export default {
  name: 'App',
  components: {
    Navbar,
    PageViewer,
    SignInModal,
    SwipeableCards
},
  data(){
    return {
        activePage : 0,
        pages: [
            {
                link: {text: 'Home', url: "home.html"},
                pageTitle: "Cornucopia!",
                subTitle: `Welcome to Cornucopia, the ultimate food lover's paradise! Are you tired of endlessly scrolling through restaurant review sites, only to still be unsure of where to go for your next meal? Look no further than Cornucopia, the website that focuses solely on restaurant suggestions and reviews of dishes. Our user-friendly interface, modeled after popular online dating apps, makes finding the perfect restaurant a breeze. No matter your preferences or dietary restrictions, we will match you with a restaurant that meets your needs and exceeds your expectations. Our extensive database of restaurants and dishes is regularly updated to ensure that you always have access to the latest and greatest culinary offerings. And for those restaurants that want to showcase their unique dishes and atmosphere, they can register with us to create a profile that will leave your taste buds tantalized. So what are you waiting for? Join the Cornucopia community today and embark on a delicious journey of restaurant discovery!`,
                components: null,
            },
            {
                link: {text: 'About', url: 'about.html'},
                pageTitle: "About Cornucopia?",
                subTitle: `Whenever we want to find places to eat, we would need to go through Google Map, Yelp and various online platforms to search for a restaurant. However, with the use of website, we think that finding a restaurant should be an experience not a chore. 

                We would like our website to focus only on restaurant suggesting and reviewing of dishes. For whatever your preferences maybe, we will find a restaurant that matches one's preference.`,
                components: null,
            },
            {
                link: {text: 'Your Restaurant', url: "card-stack.html"},
                pageTitle: "Find your best-fit restaurant",
                subTitle: "Swipe to find your meal!",
                components: {
                  SwipeableCards
                },
            },

        ],       
    };
  },
}
</script>

