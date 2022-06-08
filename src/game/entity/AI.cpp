#include "AI.hpp"

using namespace std;


vector<Angle> AI::calculatePath(Map * map, Position start, Position end){
    //Declare node

    priority_queue<Node, vector<Node>, greater<Node>> queue;

    //Add start node
    Node startNode = {start, 0};
    queue.push(startNode);

    //Declare visited
    vector<vector<int>> visited(map->getHeight(), vector<int>(map->getWidth(), -1));

    //Declare current node
    Node currentNode;

    Entity e = Entity();
    e.importMap(map);

    while (!queue.empty()){
        currentNode = queue.top();
        queue.pop();

        if (currentNode.position == end){
            break;
        }

        //Check if visited
        if (visited[currentNode.position.getY()][currentNode.position.getX()] != -1){
            continue;
        }

        //Mark as visited
        visited[currentNode.position.getY()][currentNode.position.getX()] = currentNode.distance;

        //Add neighbours
        for (int i = 0; i < 4; i++){
            Position nextPosition = currentNode.position;
            nextPosition.move(Angle(i), 1);
            e.teleportCheck(nextPosition);
            //Check if wall
            if (map->wall(nextPosition)){
                continue;
            }
            //Check if visited
            if (visited[nextPosition.getY()][nextPosition.getX()] != -1){
                continue;
            }
            //Add to queue
            Node nextNode = {nextPosition, currentNode.distance + 1};
            queue.push(nextNode);
        }
    }

    //Check if end was found
    if (currentNode.position != end){
        return vector<Angle>();
    }

    //Declare path
    vector<Angle> path;

    //Add path
    while (currentNode.position != start){
        //Find lowest distance
        int lowestDistance = INT_MAX;
        Position lowestPosition;
        for (int i = 0; i < 4; i++){
            Position nextPosition = currentNode.position;
            nextPosition.move(Angle(i), 1);
            e.teleportCheck(nextPosition);
            if (visited[nextPosition.getY()][nextPosition.getX()] != -1 && visited[nextPosition.getY()][nextPosition.getX()] < lowestDistance){
                lowestDistance = visited[nextPosition.getY()][nextPosition.getX()];
                lowestPosition = nextPosition;
            }
        }

        Angle angle;
        if (lowestPosition.getX() == currentNode.position.getX()){
            if (lowestPosition.getY() > currentNode.position.getY()){
                angle = Angle(0);
            }else{
                angle = Angle(2);
            }
        }else{
            if (lowestPosition.getX() > currentNode.position.getX()){
                angle = Angle(3);
            }else{
                angle = Angle(1);
            }
        }
        if (lowestPosition.distance(currentNode.position) > 1){
            angle += 2;
        }
        path.push_back(angle);
        currentNode.position = lowestPosition;
    }

    //Reverse path
    reverse(path.begin(), path.end());

    return path;
}

Position AI::randomPosition(Map * map){
    Position position;
    position = Position(rand() % map->getWidth(), rand() % map->getHeight());
    while (map->wall(position)){
        position = Position(rand() % map->getWidth(), rand() % map->getHeight());
    }
    return position;
}