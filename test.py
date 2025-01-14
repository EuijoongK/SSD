import struct
import cv2
import matplotlib.pyplot as plt

def load_bounding_boxes(binary_file_path):
    bounding_boxes = []
    with open(binary_file_path, 'rb') as f:
        while True:
            data = f.read(4 * 4)  # Each box consists of 4 floats (4 bytes each)
            if not data:
                break
            box = struct.unpack('ffff', data)  # Unpack 4 floats
            bounding_boxes.append(box)
    return bounding_boxes

def plot_bounding_boxes(image_path, bounding_boxes, output_path=None):
    # Load image
    image = cv2.imread(image_path)
    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)  # Convert BGR to RGB for plotting
    
    # Plot bounding boxes
    for box in bounding_boxes:
        xmin, ymin, xmax, ymax = box
        cv2.rectangle(image, (int(xmin), int(ymin)), (int(xmax), int(ymax)), color=(255, 0, 0), thickness=2)
    
    # Display image with bounding boxes
    plt.figure(figsize=(10, 10))
    plt.imshow(image)
    plt.axis('off')
    plt.show()
    
    # Save the image if output_path is provided
    if output_path:
        cv2.imwrite(output_path, cv2.cvtColor(image, cv2.COLOR_RGB2BGR))  # Convert RGB back to BGR for saving

# Example usage
binary_file_path = './data/2007_000480.bin'
image_path = './data/2007_000480.bin'
output_image_path = './output/output_image.jpg' 

bounding_boxes = load_bounding_boxes(binary_file_path)
plot_bounding_boxes(image_path, bounding_boxes, output_image_path)