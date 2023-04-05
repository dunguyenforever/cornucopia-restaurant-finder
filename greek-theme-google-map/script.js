function initMap() {
    // Initialize the map object to be shown on the screen
    map = new google.maps.Map(document.getElementById("map"), {
      mapId: "3d375f96ca2243c3",
      center: { lat: 39.13140206910473, lng: -84.51619941228316 },
      zoom: 16,
      maptypeControl: false,
      fullscreenControl: false,
      streetViewControl: false,
    });

    // Add and initialize the marker
    const standing_marker = new google.maps.Marker({
      position: { lat: 39.128546992045806, lng: -84.51730215071254 },
      map,
      title: "Standing Person Marker",
      icon: {
        url: "icon/standing_person_marker.png",
        scaledSize: new google.maps.Size(40,40) // Size(width, height[, widthUnit, heightUnit])
      },
      animation: google.maps.Animation.DROP
    });
    
    // This object is declared to open the info window upon the standing_marker
    const infowindow = new google.maps.InfoWindow({
      content: "You are standing at this location",
    });

    standing_marker.addListener("click", () => {
      infowindow.open(map, standing_marker);
    })
  }
  
  window.initMap = initMap;
  
// University of Cincinnati latitude and longtitue respectively: 
// 39.13140206910473, -84.51619941228316

// Standing Person Marker:
// 39.128546992045806, -84.51730215071254