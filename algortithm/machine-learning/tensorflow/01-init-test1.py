import tensorflow as tf

print('CPUs:', tf.config.list_physical_devices('CPU'))
print('GPUs:', tf.config.list_physical_devices('GPU'))
