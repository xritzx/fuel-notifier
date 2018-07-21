const char homepage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body style="background:rgb(33, 33, 33)">
 
<div id="Fuel Tank" style="text-align:center;">
<h1 style=" color:White;background:#3E2723; padding:5%">Fuel Notifier</h1>
    <img src="https://images.hertz.com/icons/GasIcon.png" alt="" width="40%" style="margin:auto">
</div>
<a href="https://www.google.com/maps/search/?api=1&query=petrol+pump" style="text-decoration:none">
<div style="margin:auto; width:10%; border-radius:50%; padding:20%;text-align:center; color:beige; font-size:20px; text-decoration:none" id="tank">
    <h2><span id="fuel_div">0</span>%<br></h2><br>
    <small>Click to find Gas Stations near you</small>
</div>
</a>
<script>
document.onload = Notification.requestPermission(function(res){
    if(res == 'granted'){
        pushNot();
    }
});
setInterval(function() {
  getData();
  setcolor();
}, 2000);
setInterval(pushNot, 1000);

function mapRange( value, r1, r2 ) { 
    return ( value - r1[ 0 ] ) * ( r2[ 1 ] - r2[ 0 ] ) / ( r1[ 1 ] - r1[ 0 ] ) + r2[ 0 ];
}
function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var value = mapRange(Number(this.responseText), [0,1024], [0,100]);
      document.getElementById("fuel_div").innerHTML = value;
    }
  };
  xhttp.open("GET", "readADC", true);
  xhttp.send();
}
function setcolor(){
    var col = Number(document.getElementById("fuel_div").innerHTML);
    if(col > 25){
        document.getElementById("tank").style.backgroundColor = "#33691E";
    }
    else{
        document.getElementById("tank").style.backgroundColor = "#B71C1C";
    }
}
function pushNot(){
    var val = document.getElementById("fuel_div").innerHTML;
    if(Number(val) < 25){
    var pushNoti = new Notification("Low Fuel Alert",{
        body:"Your Fuel is LOW "+val,
        icon:"https://images.hertz.com/icons/GasIcon.png"
    });
    pushNoti.onclick = function(){
        location.href = "https://www.google.com/maps/search/?api=1&query=petrol+pump";
    }}
}

</script>
</body>
</html>
)=====";


