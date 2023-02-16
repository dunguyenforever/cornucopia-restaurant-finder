# Cornucopia
## Product Proposal
### Vision 

Our restaurant finder/generator website will be using a database comprises of restaurants information and reviews from Google and Yelp to recommend to a customer where they would like to eat. 

Our targeted audience and user personas that we aim at are customers looking for a restaurant to eat and the restaurant owners in Cincinnati.

Whenever we want to find places to eat, we would need to go through Google Map, Yelp and various online platforms to search for a restaurant. However, with the use of website, we think that finding a restaurant should be an experience not a chore. For now, our product will be name Athena, but later on we will decide an official name for it. 

For the moment, our competitors like Yelp, Google and Tripadvisor also have restaurant suggestion features. They would be our primary competitors.

We would like our website to focus only on restaurant suggesting and reviewing of dishes. For whatever your preferences maybe, we will find a restaurant that matches one's preference. For now, we imagine it to have a user interface like Tinder, however, it is for food. The description for the restaurant will either be generated through the databases or restaurant owners could register with us to make their profile looks better.

### Software Architecture

The system's architecture and its components/modules as identified below

![architecture](https://user-images.githubusercontent.com/74561706/219219638-44414e8c-8b71-4c28-8626-44eddff843bd.png)

The data we will be storing include but not limited to user's personalized settings for finding restaurants, related information about restaurants like menu, prices, locations, reviews, images. We will have a total of 3 databases. The first one is the customers' database storing not only the personal information of the app user but also the data of previous "favorite" tags or categories. The second one is the providers' database containing the specific information of the restaurants for recommendation service, which will be accessed by the customers. Last but not least, we also have a memory cache to temporaily store the categories tags of the "right-swiped" restaurant for filteration and best-match worker

For the moments, we will start looking into HTML, CSS, Javascript, Node.js for the front end of our website. For the front end, we would like to place an emphasis on the seamlessness when transitioning between finding restaurants, fast responses to user input and personalized settings for restaurant suggestion. For the back-end development, we have an intention to use SQP and PHP to access and transfer data from API to database and back. We will work on and figure out the increase the speed of data transfering and minimize the chance of delays while users interact with the website.

Some other toolkits that we will look into include databases, how to store large quantity of information regarding restaurants and its reviews. Google Map API and other API related to finding restaurants will also be researched. A static website or web application hosted by AWS will be considerred in the further process throughout the semester

### Challenges and Risks
