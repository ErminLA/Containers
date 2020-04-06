<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">

    <title>Our Website</title>
  </head>
  <body style="background-color: #a6a6a6;">
  <h1 class="text-center text-primary">OUR WEBSITE</h1>
   <nav class="navbar navbar-dark bg-dark">
                <button type="button" onclick="randomNumber()" class="btn btn-primary font-weight-bold" style="width: 15%;">Random Number</button>
                <button type="button" onclick="randomVideo()" class="btn btn-primary font-weight-bold" style="width: 15%;">Random ACG Video</button>
                <button type="button" onclick="getMOTD()" class="btn btn-primary font-weight-bold" style="width: 15%;">MOTD</button>
        </nav>

   <!--display: none;
       background-color: #000000;-->
   <div id="display" class="text-center" style="display: none; margin-top: 10px; margin-left: 10%; margin-right: 10%;">
                test
   </div>


   <script>
   
    var base_url = 'https://ermin2d.mylabserver.com';
   
    function getData(callback, path) {
                        var response;                   

                        const Http = new XMLHttpRequest();
                        const url = base_url + path;
                        Http.open('GET', url, true);
                        Http.send();
                        console.log("DO I EXECUTE: getData after send");
                        console.log("FULL PATH: " + url);
                        console.log("STATUS: " + Http.status);
                        console.log("STATUS: " + Http.readyState);
                        Http.onreadystatechange = function() {
                                if(Http.readyState === 4 && Http.status === 200 && callback) 
                                        callback(Http.response);
                        }
                }
    
    function showData(response) {
                        console.log("DO I EXECUTE: showData Start");
                        $("#display").show();
                        
                        var id = "display";
                        var container = document.getElementById(id);
                        
                        html = '<div style="color: white; height: 200px;">' + response + '</div>';
                        container.innerHTML = html;
                        console.log("DO I EXECUTE: showData End");
                }
   
    function randomNumber() {
        console.log("DO I EXECUTE: randomNumber START");
        var path = '/random_number.php';
        getData(showData, path);
    }
    
    function randomVideo() {
        var path = '/youtube_video.php';
        getData(showData, path);
    }
    
    function getMOTD() {
        var path = '/motd.php';
        getData(showData, path);
    }
   
   </script>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.4.1.slim.min.js" integrity="sha384-J6qa4849blE2+poT4WnyKhv5vZF5SrPo0iEjwBvKU7imGFAV0wwj1yYfoRSJoZ+n" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js" integrity="sha384-Q6E9RHvbIyZFJoft+2mJbHaEWldlvI9IOYy5n3zV9zzTtmI3UksdQRVvoxMfooAo" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/js/bootstrap.min.js" integrity="sha384-wfSDF2E50Y2D1uUdj0O3uMBJnjuUD4Ih7YwaYd1iqfktj0Uod8GCExl3Og8ifwB6" crossorigin="anonymous"></script>
  </body>
</html>
