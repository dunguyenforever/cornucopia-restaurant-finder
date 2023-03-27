# This program will output a dedicated Excel file based on user input values for a specified location's address (address) 
# and its nearby locations preference (search_location) 
import time
import googlemaps 
import pandas 

def miles_to_meters(miles):
    try:
        return miles * 1_609.344
    except:
        return 0

# Enable Geocoding API, Geolocation API, and Places API on Google Cloud Platform
# Generated an API Key from Google Cloud Platform and utilized it
# My personal API Key is used in this project

API_KEY = open('GOOGLEMAPS_API_KEY.txt','r').read()
map_client = googlemaps.Client(API_KEY)

# Input values before running the code
address = '' # User input value for an address

search_location = 'restaurant'# User input value for the type of nearby location 

output_file_name = 'restaurant_list'# The name of the output Excel file

distance = miles_to_meters(2) # User input value for how far it is from the address to the locations
# the default input is 2 miles 
locations_list = []

geocode = map_client.geocode(address=address)
(lat, lng) = map(geocode[0]['geometry']['location'].get, ('lat', 'lng'))

response = map_client.places_nearby(
    location=(lat, lng),
    keyword=search_location,
    radius=distance
)   

locations_list.extend(response.get('results'))
next_page_token = response.get('next_page_token')

while next_page_token:
    time.sleep(2)
    response = map_client.places_nearby(
        location=(lat, lng),
        keyword=search_location,
        radius=distance,
        page_token=next_page_token
    )   
    locations_list.extend(response.get('results'))
    next_page_token = response.get('next_page_token')

df = pandas.DataFrame(locations_list)
df['url'] = 'https://www.google.com/maps/place/?q=place_id:' + df['place_id']
df.to_excel('{0}.xlsx'.format(output_file_name))