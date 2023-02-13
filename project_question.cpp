#include<bits/stdc++.h>
using namespace std;

class Scheduler {
  List<Room> rooms = new LinkedList();
  Scheduler(rooms) {
    this.rooms=rooms;
  }
  
  book(start,end) {
    for (room:rooms) {
      Meeting meeting = room.book(start,end);
      if (meeting!=null){
        deque(meeting);
        return room.name;
      }
    }
    return '';
  }
}


class Room {
  String name = "";
  Calendar cal = null;
  List<Meeting> meetings = new LinkedList();
  
  Room(name) {
    this.name=name;
    this.cal=new Calendar(this);
  }
  
  Meeting book(Date start, Date end) {
    Meeting meeting = this.cal.book(start, end);
    if (meeting!=null) {
      meetings.add(meeting);
    }
    return meeting;
  }
}

class Calendar {
  
  Room room=null;
  
  Calendar(Room room){
    this.room=room;
  }
  
  Meeting book(Date start, Date end){
    if avaiable(start, end){
      Meeting m = new Meeting(start, end, room);
      occupy(start, end);
    }
  }
}


class Meeting {
  String id='';
  Room room=null;
  Date start=null;
  Date end=null;
  Meeting(Date start, Date end, Room room) {
    this.id=UUID.generate();
    this.start=start;
    this.end=end;
    this.room=room;
  }
}