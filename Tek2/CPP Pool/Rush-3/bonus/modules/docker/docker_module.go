package docker

import (
	"fmt"
	"context"

	"github.com/docker/docker/client"
	"github.com/docker/docker/api/types"
	"github.com/dustin/go-humanize"
)

// DockerWidget : docker widget
type DockerWidget struct {
	cli		*client.Client
	buffer 	string
}

// Init : init DockerWidget Structure
func (docker *DockerWidget) Init() {
	cli, err := client.NewEnvClient()
	if err != nil {
		fmt.Println(err)
	} else {
		docker.cli = cli
	}
}

// GetBuffer : get buffer to display in TextView
func (docker DockerWidget) GetBuffer() string {
	return docker.buffer
}

// GetSystemInfo : fill docker widget structur
func (docker *DockerWidget) GetSystemInfo() {
	info, err := docker.cli.Info(context.Background())
	if err != nil {
		docker.buffer = "[#21BDC2]Sytem[white] :\n\nCould not get docker system info\nCannot connect to the Docker daemon at unix:///var/run/docker.sock. Is the docker daemon running?"
		return
	}
	diskUsage, err := docker.cli.DiskUsage(context.Background())
	if err != nil {
		docker.buffer = "[#21BDC2]Sytem[white] :\n\nCould not get disk usage"
		return
	}

	var duContainer int64
	for _, c := range diskUsage.Containers {
		duContainer += c.SizeRw
	}
	var duImg int64
	for _, im := range diskUsage.Images {
		duImg += im.Size
	}
	var duVol int64
	for _, v := range diskUsage.Volumes {
		duVol += v.UsageData.Size
	}
	docker.buffer = fmt.Sprintf("[#21BDC2]System[white]\n\nName: [yellow]%s[white]\n", info.Name)
	docker.buffer = fmt.Sprintf("%sVersion: [yellow]%s[white]\n", docker.buffer, info.ServerVersion)
	docker.buffer = fmt.Sprintf("%sroot: [yellow]%s[white]\n", docker.buffer, info.DockerRootDir)
	docker.buffer = fmt.Sprintf("%sContainer: [yellow]%d[white]/[yellow]%d[white]/[yellow]%d[white]\n", docker.buffer, info.ContainersRunning, info.ContainersPaused, info.ContainersStopped)
	docker.buffer = fmt.Sprintf("%sImages: [yellow]%d[white]\n", docker.buffer, info.Images)
	docker.buffer = fmt.Sprintf("%sVolumes: [yellow]%v[white]\n", docker.buffer, len(diskUsage.Volumes))
	docker.buffer = fmt.Sprintf("%sMemory limit: [yellow]%s[white]\n", docker.buffer, humanize.Bytes(uint64(info.MemTotal)))
	// docker.buffer = fmt.Sprintf("%sroot: [yellow]%s[white]", docker.buffer, info.DockerRootDir)
}

// GetContainerInfo : fill buffer with ContainerInfo
func (docker *DockerWidget) GetContainerInfo() {
	container, err := docker.cli.ContainerList(context.Background(), types.ContainerListOptions{All: true})
	if err != nil {
		docker.buffer = fmt.Sprintf("%s\n\n[#21BDC2]Container[white] :\n\nCould not get container list\n", docker.buffer)
		return
	}
	if len(container) == 0 {
		docker.buffer = fmt.Sprintf("%s\n\n[#21BDC2]Container[white] :\n\nNo container\n", docker.buffer)
		return
	}

	// Create buffer list container
	docker.buffer = fmt.Sprintf("%s\n\n[#21BDC2]Container[white] :\n", docker.buffer)
	for _, c := range container {
		docker.buffer = fmt.Sprintf("%s\n[blue]ID[white] : %s [red]Command[white] : %s [yellow]Name[white] : %s [green]Status[white] : %s", docker.buffer, c.ID, c.Command, c.Names[0], c.Status)
	}
}
