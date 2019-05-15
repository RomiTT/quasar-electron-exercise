<template>
  <q-scrollable-page pageId="index-vue-page" mainHeaderId="my-layout-header" class="flex flex-start column">
    <img alt="Quasar logo" src="~assets/quasar-logo-full.svg" />   
  </q-scrollable-page>
</template>

<style scoped>
</style>

<script>
// @ is an alias to /src
import QScrollablePage from '../components/QScrollablePage.vue'

export default {
  name: "PageIndex",
  components: {
    QScrollablePage
  },
  data() {
    return {}
  },
  props: {},
  computed: {},
  methods: {}
};
</script>
