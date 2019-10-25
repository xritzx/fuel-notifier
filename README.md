# fuel-notifier
Notifies When fuel level drops below 25%
Here we  serve a webpage in our localhost:443 that shows us the amount fuel/content left in our tank along with a hyperlink that shows the users all available gas stations
in users' present location.
Notifications service has been withdrawn from http server in all modern browsers, only servers with https certification allows notification access.
Unfortunately our ESP8266 is hosting the webpage locally and can only have a self-signed certificate which is again blocked in all modern web browsers
thus having only http server in hand what we can do is have a third party notification sender like Telegram or IFTTT, in which each user has to have a account
in the said services get authorization token and use it in the NodeMCU device to have the utility of Notification services

