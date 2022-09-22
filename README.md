# arduinoDay grafana repository 

Acess 
<a href="https://github.com/tobiasschuerg/InfluxDB-Client-for-Arduino">this link</a> to learn about the API used to write data direct from esp to Influx. 
And <a href="https://github.com/tobiasschuerg/InfluxDB-Client-for-Arduino/blob/master/examples/BasicWrite/BasicWrite.ino">here</a>  the example that I used to write the esp 8266 code.

# Setting Influx
To start influx db just unzip the folder and start the influxd.exe. While it is open the influx is running. Now open a cmd in influx folder, type influx and press enter. You will see something like this:

![alt text](https://github.com/Angar0th/arduinoDay/blob/master/instructions%20to%20grafana/influx_cmd.png)

Then type the follow command to create a new database:
>CREATE DATABASE arduinoDay

To see if database was created, type "show databases" and see a list of all databases. If it's ok, create admin user to this database with this commands:
>CREATE USER "admin" WITH PASSWORD 'admin'

>use arduinoDay

>GRANT ALL ON "arduinoDay" TO "admin"

# Setting Grafana
Install grafana using the installer to windows (available in this repository), see <a href="https://grafana.com/docs/grafana/latest/installation/windows/">here</a> how to install. After this, open a browser and type this address "localhost:3000", if grafana was 
successfully installed, you will see a login page like this:
![alt text](https://github.com/Angar0th/arduinoDay/blob/master/instructions%20to%20grafana/grafana_login.png)

The default login is "admin" and password "admin".

Once you logged, you can create a data source with you influx database, so click in "Create a data source" and choose influxDB, you will be in a configuration page like this image:

![alt text](https://github.com/Angar0th/arduinoDay/blob/master/instructions%20to%20grafana/grafana_db_config.png)

Just configure like this image and press the green button "Save & Test", if everything is right, you will see a message saying that the data source is working, so click in "Back" button and you can create a new dash board:
![alt text](https://github.com/Angar0th/arduinoDay/blob/master/instructions%20to%20grafana/new_dashboard.png)
Then you will be in a new dashboard, so click to add a query:
![alt text](https://github.com/Angar0th/arduinoDay/blob/master/instructions%20to%20grafana/new_dashboard_2.png)
In the new window will be a field to do a query in database, click in the pen to change to text mode:
![alt text](https://github.com/Angar0th/arduinoDay/blob/master/instructions%20to%20grafana/new_dashboard_2_5.png)
So confirm if the database selected is correct and type the following query:
> SELECT Temperature FROM data WHERE $timeFilter
![alt text](https://github.com/Angar0th/arduinoDay/blob/master/instructions%20to%20grafana/new_dashboard_3.png)
When you click out of query field, the data will start to appear on the graphic. On the top-right side you can adjust the time axis and refresh time like this:
![alt text](https://github.com/Angar0th/arduinoDay/blob/master/instructions%20to%20grafana/new_dashboard_4.png)
And finally you can explore more about grafana visualization:
![alt text](https://github.com/Angar0th/arduinoDay/blob/master/instructions%20to%20grafana/new_dashboard_5.png)

Find more about influx usage on the documentation:
https://docs.influxdata.com/influxdb/v1.7/introduction/getting-started/
