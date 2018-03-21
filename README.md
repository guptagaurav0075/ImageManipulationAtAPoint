# ImageManipulationAtAPoint


SJSU - CS 235 Mid Term – Code Development Problem


A Rotation Manipulator with a Moveable Pivot Point (Centre of Rotation)
In this problem, you will complete implementation of a new type of rotation manipulator with adjustable pivot point. For a demo, please see provided video.

####Basic Functionality

```For this application, the basic functionality can be described as follows:
• The user can rotate an image using the purple handle. The handle can move anywhere in the window.
• The image rotates about the pivot point at the green handle.
• The green handle (pivot point) can be moved anywhere in the window.
• The user can drag and drop images into the window and delete them with <del> or with “d”.
• The user can reset the position of the to a neutral position with the “c” key. Steps Required
```

The student will complete development of the manipulator by implementing just the mousePressed(), mouseDragged() and mouseReleased() Functions. The following steps have specified credit given to each.

1. Implement just the dragging the pivot and rotator handles (individually) around on the image without affecting anything (yet). To test if the mouse is inside the handle, see Handle::inside(); These handles are already declared in ofApp.h. The handles have their own position since they inherit from BaseObject (trans.x, trans.y)

2. Implement rotation about the pivot point by dragging the purple handle. Hint: consider the vector created by the rotator handle and the pivot point when the mouse goes down. Moving the rotator handle creates a new vector. The angle between the two vectors is the angle of rotation. The direction of the rotation can be determined using the cross product.

3. Implement the pivot move functionality. Hint: You can set the pivot (in object space) using Image::setPivot(). To go from screen space (the space that the handle is in) to image space, use the function provided in Image class. Set the pivot only once on mouse up. You must also translate image to the new screen space pivot point after. 
