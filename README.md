# Raindrop-PointCloud-Filter
LiDAR PCL filter based on DBSCAN and Geometric Constrant

This is part of work from the dissertation of the author in NTU. The aim of this project is to filter out raindrops detected by LiDAR sensor in the point cloud. 

The feature of pointcloud in rainy weather: the raindrop has the quality to produce echo to LiDAR sensors and therefore will be detected as points with low to medium intensity(10-50). However, the raindrop points are sparse and irregular, making the density-based clustering method potentially applicable for raindrop outlier filtering. There are two main challenges of filtering out raindrop using cluster method: one is the existence of tree leaves, and the other is the water on the ground will result in sparse pointcloud generation. The tree leaves are presented as sparse point cluster in pointcloud map. According to experiment, when being detected far away from the LiDAR, a few part of the leaves on one tree will be detected and might be filtered as raindrops. The solution is to apply passthrough filter, choosing to filter the points within specific distance so that the potential tree leaves will be detected together with its neighbor leaves. For the water puddle on the ground, it will insulate the ground and avoid the ground from producing echo. The result is few points on the ground will be detected and the sparse pointcloud might be clustered as raindrops. The solution is to take advantage of reflection intensity and passthrough filter.

Additionally, intensity filter is used to correct false clustering.
The filtering result is shown below.
![RB@}B{_QPKZ ZKRCJ_J_6WE](https://user-images.githubusercontent.com/70008102/213177103-907aed23-3066-4188-960b-f680be591824.png)

