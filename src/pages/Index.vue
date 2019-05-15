<template>
  <q-page id="index-vue-page" class="flex flex-start column" style="overflow:auto;">
    <img alt="Quasar logo" src="~assets/quasar-logo-full.svg" />   
  </q-page>
</template>

<style scoped>
</style>

<script>
export default {
  name: "PageIndex",
  data: () => {
    return {}
  },
  props: {},
  computed: {},
  methods: {},
  mounted: () => {
    var header = document.getElementById("my-layout-header")
    var page = document.getElementById("index-vue-page")
    page.style.height= `${window.innerHeight-header.offsetHeight}px`

    window.onresize = () => {
      page.style.height= `${window.innerHeight-header.offsetHeight}px`
    }
  }
};
</script>
