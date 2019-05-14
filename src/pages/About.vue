<template>
  <q-page padding>
    <div class="version-info">
      <h6>Quasar: {{ $q.version }}</h6>
      <h6>Node.js : <span>{{nodeVersion}}</span></h6>
      <h6>Chrome : <span>{{chromeVersion}}</span></h6>
      <h6>Electron: <span>{{electronVersion}}</span></h6>
    </div>
  </q-page>
</template>

<script>
export default {
  name: 'About',
  data: () => {
    return {}
  },
  props: {},
  computed: {
    nodeVersion: {
      get: () => {
        return process.versions.node;
      }
    },
    chromeVersion: {
      get: () => {
        return process.versions.chrome;
      }
    },
    electronVersion: {
      get: () => {
        return process.versions.electron;
      }
    }
  },
  methods: {}
}
</script>

<style scoped>
.version-info {
  text-align: left;
  padding: 2%;
}
.version-info > h6 {
    margin:0;
    padding-top: 1%;
    padding-bottom:1%;
    color:blue;
}
</style>
