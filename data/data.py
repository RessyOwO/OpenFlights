import pandas as pd

#read the files
airports = pd.read_csv("airports.txt")
routes = pd.read_csv("routes.txt")

#drop all the unneeded columns
airports = airports.drop(['Airport ID','City','Country','ICAO','Altitude','Timezone','DST','Tz','Type','Source'],axis = 1)
routes = routes.drop(['Airline','Airline ID','Source airport ID','Destination airport ID','Codeshare','Stops','Equipment'], axis = 1)

#save the new data
airports.to_csv("new_airports.txt")
routes.to_csv("new_routes.txt")