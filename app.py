from flask import Flask
from flask_cors import CORS
import mysql.connector as mariadb


import random
import hashlib
import json

app = Flask(__name__)
CORS(app)

@app.route("/")
def initialTest():
        return "TEST"

@app.route("/youtube_video")
def youtube_video():
        base_url = "https://www.youtube.com/embed/"
        video_ids = [   "h8xYLsmGnEQ",
                        "wZ31Tk2OxyE",
                        "6_IGyMM3QKE",
                        "E7WKVMkF98Q",
                        "g8kJnFTz87M",
                        "ADvYULvHs6Y",
                        "hA-onpcn__8",
                        "WBFb5x6g4dA",
                        "1PPGUOBzzKY",
                        "8xjBwTq2Dss",
                        "iI-cAtKgPXs",
                        "piu-TK00j_c",
                        "7te-pqNAl4o",
                        "s9_L_6r1Eh4",
                        "PZs7MImMOy8",
                        "LJi1FXLINgA",
                        "sGOlcIVd4Dw",
                        "h7a4ATtwkGI",
                        "4bSNfzucG8A"   ]
        return '<iframe width="560" height="315" src="' + base_url + video_ids[random.randint(0,18)] + '"></iframe>'

@app.route("/random_number")
def random_number():
        return '<h1>' + hashlib.sha224(str(random.randint(1, 10149583095834095834059349)).encode()).hexdigest() + '</h1>'

@app.route("/motd")
def motd():
        mariadb_connection = mariadb.connect(user='chronic', password='Test321', database='MyDB')
        cursor = mariadb_connection.cursor()
        cursor.execute("SELECT msg FROM motd;")
        #cursor.close()

        msg = cursor.fetchall()[random.randint(0,8)][0]
        mariadb_connection.commit()

        return str(msg)

@app.route("/set_motd")
def set_motd():
        msg1 = "Whoever said that the definition of insanity is doing the same thing over and over again and expecting different results has obviously never had to reboot a computer."
        msg2 = "Programmer\’s girlfriend: Are you going to sit and type in front of that thing all day or are you going out with me?\nProgrammer: Yes."
        msg3 = "What do you call 8 hobbits?\nA hobbyte"
        msg4 = "How many programmers does it take to change a light bulb?\nNone. It\'s a hardware problem."
        msg5 = "I broke my finger last week. On the other hand I\'m ok."
        msg6 = "What did the computer do at lunchtime?\nHad a byte"
        msg7 = "Once a programmer drowned in the sea. Many Marines where at that time on the beach, but the programmer was shouting F1 F1 and nobody understood it."
        msg8 = "Unix is user friendly. It\'s just very particular about who it\'s friends are.\""
        msg9 = "How many software testers does it take to change a light bulb?\nNone. We just recognized darkness, fixing it is someone else\'s problem."

        messages = [msg1, msg2, msg3, msg4, msg5, msg6, msg7, msg8, msg9,]

        mariadb_connection = mariadb.connect(user='chronic', password='Test321', database='MyDB')
        cursor = mariadb_connection.cursor()

        counter = 0
        for m in messages:
                cursor.execute("INSERT INTO motd(msg) VALUES(%s);", (messages[counter],))
                counter += 1

        mariadb_connection.commit()
        cursor.close()

        return "DONE"


if __name__ == '__main__':
        app.run(debug=True,host='0.0.0.0',port=65535)
