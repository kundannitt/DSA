import cv2
import numpy as np
import copy
def draw_couinaud_segments(image):
    # Define segment boundaries (x1, y1, x2, y2)
    segment_boundaries = {
        'Segment I': (0, 0, image.shape[1]//3, image.shape[0]//3),
        'Segment II': (image.shape[1]//3, 0, 2*image.shape[1]//3, image.shape[0]//3),
        'Segment III': (2*image.shape[1]//3, 0, image.shape[1], image.shape[0]//3),
        'Segment IV': (0, image.shape[0]//3, image.shape[1]//3, 2*image.shape[0]//3),
        'Segment V': (image.shape[1]//3, image.shape[0]//3, 2*image.shape[1]//3, 2*image.shape[0]//3),
        'Segment VI': (2*image.shape[1]//3, image.shape[0]//3, image.shape[1], 2*image.shape[0]//3),
        'Segment VII': (0, 2*image.shape[0]//3, image.shape[1]//3, image.shape[0]),
        'Segment VIII': (image.shape[1]//3, 2*image.shape[0]//3, 2*image.shape[1]//3, image.shape[0]),
        'Caudate lobe': (2*image.shape[1]//3, 2*image.shape[0]//3, image.shape[1], image.shape[0])
    }

    colors = {
        'Segment I': (255, 0, 0),    # Blue
        'Segment II': (0, 255, 0),   # Green
        'Segment III': (0, 0, 255),   # Red
        'Segment IV': (255, 255, 0), # Cyan
        'Segment V': (0, 255, 255),  # Yellow
        'Segment VI': (255, 0, 255), # Magenta
        'Segment VII': (128, 0, 128), # Purple
        'Segment VIII': (128, 128, 0), # Olive
        'Caudate lobe': (0, 128, 128) # Teal
    }

    for segment, (x1, y1, x2, y2) in segment_boundaries.items():
        cv2.rectangle(image, (x1, y1), (x2, y2), colors[segment], -1)
        cv2.putText(image, segment, (x1 + 10, y1 + 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)

    return image

# Load an image of the liver
image = cv2.imread('liver.jpg')

# Draw Couinaud segments on the image
segmented_image = draw_couinaud_segments(image.copy())

# Display the image
cv2.imshow('Couinaud Segments', segmented_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
