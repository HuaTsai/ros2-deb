# ros2-deb

Create a simple ros2 debian file.

## Build

```bash
sudo apt install python3-bloom python3-rosdep fakeroot debhelper dh-python
cd src/mypubsub
bloom-generate rosdebian
fakeroot debian/rules binary
# debian file will be generated in the parent folder
```

## Testing

```
sudo dpkg -i ros-rolling-mypubsub_1.0.0-0noble_amd64.deb
# Node, two terminals
ros2 run mypubsub pub_node
ros2 run mypubsub sub_node
# Container
ros2 launch mypubsub mypubsub.launch.py
```
